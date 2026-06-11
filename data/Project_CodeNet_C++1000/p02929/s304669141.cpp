#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=212345;
int n,c=1,now,pre;
char s[maxn];
int main()
{
    scanf("%d%s",&n,s);
    if (s[0]=='W') return 0*puts("0");
    int res=1;
    for (int i=1;i<n+n;++i) {
        now=(s[i]==s[i-1])^pre;
        if (now) res=1ll*res*c%mod,--c;
        else ++c;
        pre=now;
    }
    if (c) return 0*puts("0");
    else {
        for (int i=2;i<=n;++i) res=1ll*res*i%mod;
        printf("%d\n",res);
    }
    return 0;
}
