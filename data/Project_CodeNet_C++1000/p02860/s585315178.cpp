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
    fgets(s, n + 1, stdin);
    if(n%2==1)
        printf("No");
    else 
    {
        if(strncmp(s,s+n/2,n/2)==0)
            printf("Yes");
        else
            printf("No");
    }
}