#include<cstdio>
#include<cstring>

const int MAXN = 100 + 10;
char s[MAXN], t[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    scanf("%s %s", s, t);
    for (int i = 0; i < n;i++)
        printf("%c%c", s[i], t[i]);
    return 0;
}