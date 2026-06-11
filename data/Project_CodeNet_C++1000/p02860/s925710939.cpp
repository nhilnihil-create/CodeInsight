#include<cstdio>
#include<cstring>

const int MAXN = 100 + 10;
char s[MAXN];

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
    getchar();
    fgets(s, n + 1,stdin);
    if(n%2==1)
        printf("No");
    else 
    {
        for (int i = 0; i < n / 2;i++)
        {
            if(s[i]!=s[i+n/2])
            {
                printf("No");
                return;
            }
        }
        printf("Yes");
    }
}