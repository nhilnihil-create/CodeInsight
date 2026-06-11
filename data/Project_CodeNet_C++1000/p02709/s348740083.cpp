#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <cmath>
#define ls(x) x<<1
#define rs(x) x<<1|1
#define low(x) (x&-x)
#define mp make_pair
#define X first
#define Y second
#ifdef _DEBUG
    const int N=1e3+10;
#else
    const int N=2e3+10;
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef double db;
const ll mod=1e9+7;
template<typename T> inline T gcd(T a,T b){return !b?a:gcd(b,a%b);}
template<typename T> inline T q_pow(T a,T x){T ans=1,tmp=a;while(x){if(x&1)(ans*=tmp)%=mod;(tmp*=tmp)%=mod;x>>=1;}return ans;}
template<typename T> inline void re(T &N){int f=1;char c;while((c=getchar())< '0'||c> '9')if(c=='-')f=-1;N=c-'0';while((c=getchar())>='0'&&c<='9')N=N*10+c-'0';N*=f;}
int m,n,t=1;
ll d[N][N];
pl a[N];
ll dfs(int l,int r)
{
    if(d[l][r]!=-1)return d[l][r];
    if(l==r)return a[1].X*abs(a[1].Y-l);
    d[l][r]=max(d[l][r],dfs(l+1,r)+abs(l-a[r-l+1].Y)*a[r-l+1].X);
    d[l][r]=max(d[l][r],dfs(l,r-1)+abs(r-a[r-l+1].Y)*a[r-l+1].X);
    return d[l][r];
}
int main()
{
    // freopen("data.txt","r",stdin);
    memset(d,-1,sizeof(d));
    re(n);
    for(int i=1;i<=n;i++)re(a[i].X),a[i].Y=i;
    sort(a+1,a+n+1);
    printf("%lld\n",dfs(1,n));
    return 0;
}