#include <stdio.h>

void bs(int *a, int l, int r, int* s, int* p)
{
    if(r-l<=0)
        return;
    int l1 = l;
    int r1 = r;
    int m = a[(l+r)/2];
    while(l1 < r1)
    {
        while(l1!=(l+r)/2)
        {
            if (a[l1]<m)
            {
                printf("сравниваются слева: %d %d\n", a[l1], m);
                l1 += 1;
                *s += 1;
            }
            else
            {
                break;
            }
        }
        while(r1!=(l+r)/2)
        {
            if(a[r1]>m)
            {
                printf("сравниваются справа: %d %d\n", m, a[r1]);
                r1 -= 1;
                *s += 1;
            }
            else
            {
                break;
            }
        }
        if(l1 < r1)
        {
            *p+=1;

            printf("меняются местами: %d %d\n", a[l1],a[r1]);
            int jjj = a[l1];
            a[l1] = a[r1];
            a[r1] = jjj;

            r1-=1;
            l1+=1;
        }
        else
        {
            l1 += 1;
            break;
        }
    }
    bs(a, l, r1, s, p);
    bs(a, l1, r, s, p);
}

void puzirek(int *a, int r, int* s, int* p)
{
    for(int i = 0; i < r; ++i)
    {
        for (int j = 1; j < r-i; ++j)
        {
            *s+=1;
            if(a[j] < a[j - 1])
            {
                int b = a[j-1];
                a[j-1]=a[j];
                a[j]=b;
                *p+=1;
            }
        }
    }
}

int main()
{
    while (1 > 0)
    {
        int p=0;
        int s=0;
        int n;

        printf("\nvvedite nomer sortirovki:\n");
        scanf("%d", &n);
        if(n==1)
        {
            int k;
            printf("\nvvedite razmer massiva:\n");
            scanf("%d",&k);
            int a[k];
            printf("\nvvedite massiv:\n");
            for (int i = 0; i < k; ++i)
            {
                scanf("%d",&a[i]);
            }
            printf("\n");
            puzirek(a, k, &s, &p);
            printf("sravnenia: %d   perestanovki: %d", s,p);
        }
        if(n==2)
        {
            int k;
            printf("\nvvedite razmer massiva:\n");
            scanf("%d",&k);
            int a[k];
            printf("\nvvedite massiv:\n");
            for (int i = 0; i < k; ++i)
            {
                scanf("%d",&a[i]);
            }
            bs(a, 0, k - 1, &s, &p);

            printf("\nsravnenia: %d   perestanovki: %d\n", s,p);
        }
    }
    return 0;
}
