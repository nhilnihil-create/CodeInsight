#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rusha scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
#define rushb scanf("%d",&t);while(t--)
#define debug(x) cout<<"LBWNB    "<<x<<"---\n"
#define pb push_back
#define pii pair<int,int>
#define vii vector<int>
#define fi first
#define se second
#define mp make_pair
#define p() puts("")
#define mem(a,b) memset(a,b,sizeof a)
#define all(x) (x.begin(),x.end())
#define judgef printf("%s\n",f?"Yes":"No")
#define Judgef printf("%s\n",f?"YES":"NO")
#define sz(x) ((int)(x).size())
#define sf(x) (sizeof(x))
using namespace std;
typedef long long ll;
typedef double db;
//const int mod=998244353;
const int mod=1e9+7;
//const int inf=1e9+7;
const int maxn=2e3+10;
inline ll ksm(ll x,ll y){ ll res=1; while(y){if(y&1) res=res*x%mod;
x=x*x%mod; y>>=1;} return res; }
inline ll inv(ll a,ll p){if(a==1)return 1;return (p-p/a)*inv(p%a,p)%p;}

int t,n,m,k;
int main(){
	ll n,ans=2;
	cin>>n;
	if(n==2) ans=1;
	for(ll k=2,i=n;k*k<=n;k++,i=n){
        if(k*k==n-1) {ans++;break;}
        if((n-1)%k==0&&k*k!=(n-1)) {ans+=2;continue;}
		while(i>=k) i%k?i%=k:i/=k;
		if(i==1) ans++;
		
	}
	cout<<ans<<endl;
	return 0;
}


