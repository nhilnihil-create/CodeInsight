#include<bits/stdc++.h>
#define forn(i, s, t) for (int i = s ; i < (int)t ; i++)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf(x) printf("%d\n",x)
#define each(x) for(auto it:x)  cout<<it<<endl;
#define pi pair<int,int>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define pf(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define mem(a,x) memset(a,x,sizeof(a))
#define copy(b,a) memcpy(a,b,sizeof(a))
#define SZ(x) (int)x.size()
#define VI vector<int>
#define VII vector<pair<int,int>>
#define PI pair<int,int>
using namespace std;
typedef long long ll;
ll qpow(ll x,ll y,ll p){ll ans=1;for(x%=p;y;y>>=1,x=x*x%p)if(y&1) ans=ans*x%p;return ans;}
ll inv(ll x,ll p){return x<=1?1:(p-p/x)*inv(p%x,p)%p;}
ll sqrt2(ll x){ll l=1,r=2e9;while(l<r){ll mid=(l+r+1)>>1;if(mid*mid<=x) l=mid;else r=mid-1;}return l;}
ll sqrt3(ll x){ll y=(ll)(powl((long double)x,1.0/3.0)+0.5);while(y*y*y<x) y++;while(y*y*y>x) y--;return y;}
ll comb(ll n,ll m,ll p){if(m>n||n<0) return 0;if(m>n-m) m=n-m;ll ans=1;for(int i=1;i<=m;i++)ans=ans*n%p,ans=ans*inv(i,p),n--;return ans;}
ll comb(ll n,ll m){if(m>n||n<0) return 0;if(m>n-m) m=n-m;ll ans=1;for(int i=1;i<=m;i++)ans=ans*n,ans/=i,n--;return ans;}
ll ceil(ll x,ll y){return (x+y-1)/y;}
int lowerbit(int x) {return x&-x;}
int HighBit(int x){for(int i=30;i>=0;i--)if(x>>i&1) return i;}
const int maxn=2e5+5;
int A[maxn],B[maxn],n;
 
int main(){
	sc(n);
	for(int i=1;i<=n;i++){
		sc2(A[i],B[i]);
	}	
	sort(A+1,A+n+1);
	sort(B+1,B+n+1);
	if(n&1) {
		cout<<B[(n+1)/2]-A[(n+1)/2]+1;
	}
	else {
		cout<<B[n/2]+B[n/2+1]-A[n/2]-A[n/2+1]+1;
	}
}