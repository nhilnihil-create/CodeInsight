#include<cstdio>
#include<cstring>

void solve();
int main()
{
    solve();
    return 0;
}

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 10;i++)
    {
        if(n%i==0)
        {
            if(n/i<10)
            {
                printf("Yes");
                return;
            }
        }
    }
    printf("No");
}
