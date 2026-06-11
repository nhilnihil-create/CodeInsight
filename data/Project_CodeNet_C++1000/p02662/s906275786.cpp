#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N = 1e4+5;
const int M = 1e6+5;
const int Mod = 998244353;
#define pi acos(-1)
#define INF 1e8
#define INM INT_MIN
#define pb(a)  push_back(a)
#define mk(a,b) make_pair(a,b)
#define dbg(x) cout << "now this num is " << x << endl;
#define met0(axx) memset(axx,0,sizeof(axx));
#define metf(axx) memset(axx,-1,sizeof(axx));
#define sd(ax) scanf("%d",&ax)
#define sld(ax) scanf("%lld",&ax)
#define sldd(ax,bx) scanf("%lld %lld",&ax,&bx)
#define sdd(ax,bx) scanf("%d %d",&ax,&bx)
#define sddd(ax,bx,cx) scanf("%d %d %d",&ax,&bx,&cx)
#define sfd(ax) scanf("%lf",&ax)
#define sfdd(ax,bx) scanf("%lf %lf",&ax,&bx)
#define pr(a) printf("%d\n",a)
#define plr(a) printf("%lld\n",a)
/*
dp[i][j]表示选前i个元素,值为j的集合个数

转移方程:dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i]];//选第i个元素或者不选.

3 3
*/
LL dp[3005][3005],a[3005];
int main()
{
    int n,s;sdd(n,s);
    for(int i=1;i<=n;++i) sld(a[i]);
    dp[0][0] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=s;++j)
        {
            dp[i][j] = dp[i-1][j]*2%Mod;//对于前i-1个,已经有了凑成s的方案,贡献不断*2.
            if(j-a[i] >= 0 ) dp[i][j] = (dp[i][j]+dp[i-1][j-a[i]])%Mod;
        }
    }
    plr(dp[n][s]);
    //system("pause");
    return 0;
}