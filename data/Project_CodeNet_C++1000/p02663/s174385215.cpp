#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int>vi;
typedef vector<ll>VI;
typedef pair<int,int>pii;
typedef pair<pii,int>Pii;
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lowbit(x) ((x)&((x)^((x)-1)))
#define sz(x) int(x.size())
#pragma GCC optimize(2)
const int N=1e6+10;
const ll mod=1e9+7;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll qpow(ll a,ll b){ll s=1;while(b>0){if(b&1)s=s*a%mod;a=a*a%mod;b>>=1;}return s;}
ll C(ll n,ll m){ ll a=1,b=1; if (m>n-m) m=n-m; if (m<0) return 0;
 while(m){ a=a*n%mod; b=b*m%mod; m--; n--;} return a*qpow(b,mod-2)%mod;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
void init() {ios::sync_with_stdio(false); cin.tie(0);}
const double PI=3.1415926535897932;


int main(){
	init();
    int a,b,c,d,e; cin>>a>>b>>c>>d>>e;
	cout<<max(0,c*60+d-(a*60+b)-e); 
	return 0;
}










