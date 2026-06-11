#include <bits/stdc++.h>
//#pragma GCC optimize(2)

using namespace std;
#define LL long long
#define Rint register int
#define U unsigned
#define forn(i,a,b) for(int i = a;i <= b;++i)
#define nfor(i,a,b) for(int i = a;i >= b;--i)
#define pii pair<int ,int>
#define MS0(X) memset(X,0,sizeof(X))
#define MSf(X) memset(X,false,sizeof(X))
#define MS1(X) memset(X,-1,sizeof(X))
#define BR printf("--------------------\n")
#define pb push_back
#define rep(i,a,b) for(Rint i=a;i<=b;++i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const double PI=atan(1.)*4.;
const int maxn=1e6+5;
const int inf = 0x3f3f3f3f;
const int mod=1e9+7;
const double e=2.71828182845904523536;
int dirx[8]={1,0,-1,0,1,-1,-1,1};
int diry[8]={0,1,0,-1,1,1,-1,-1};
int n;
int a[maxn];
LL cnt[maxn],sum[maxn],ans[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        sum[cnt[a[i]]]++;
    }
    for(int i=0;i<=n;i++)
    {
        sum[i]+=sum[i-1];
    }
    int now=0;
    for(int k=n;k>=1;k--)
    {
        while(now<n&&(sum[now+1]>=1ll*k*(now+1)))now++;
        ans[k]=now;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}