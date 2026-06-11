#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,ans2,suf,gao=1;
int n,p,cnt[200005];
char s[200005];

int main()
{
    scanf("%d%d%s",&n,&p,s);
    cnt[0]=1;
    for(int i=0;i<n;i++) ans2+=((s[i]-'0')%p==0)*(i+1);
    for(int i=n-1;i>=0;i--)
    {
        suf=(suf+(s[i]-'0')*gao)%p;
        gao=10*gao%p;
        ans+=cnt[suf];
        cnt[suf]++;
    }
    printf("%lld",p==2||p==5?ans2:ans);
    return 0;
}