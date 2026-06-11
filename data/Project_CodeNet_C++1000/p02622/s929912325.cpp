#include<cstdio>
#include<cstring>

const int MAXN = 2e5 + 10;
char s[MAXN], t[MAXN];

int main()
{
    fgets(s, MAXN, stdin);
    fgets(t, MAXN, stdin);
    int n,count=0;
    n = strlen(s);
    for (int i = 0; i < n;i++)
    {
        if(s[i]!=t[i])
            count++;
    }
    printf("%d", count);
    return 0;
}