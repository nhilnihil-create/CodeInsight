#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(void)
{
    ll ans = 0;

    char s[201];
    scanf("%s", s);

    ll k;
    scanf("%lld", &k);

    int n = strlen(s);
    char tmp[201];
    strcpy(tmp, s);
    strcat(tmp, s);

    int flag = 1;
    rep(i, n - 1) if (s[i] != s[i + 1])
    {
        flag = 0;
        //puts("flag=0");
    }

    int first = 0;
    rep(i, n) if (s[i] == s[i + 1])
    {
        s[i + 1] = 'A';
        first++;
    }

    int second = 0;
    rep(i, n * 2) if (tmp[i] == tmp[i + 1])
    {
        tmp[i + 1] = 'A';
        second++;
    }

    if (flag)
        ans = n * k / 2;
    else
        ans = (ll)first + (ll)(second - first) * (k - 1);

    //printf("%s\n", s);
    printf("%lld\n", ans);

    return 0;
}