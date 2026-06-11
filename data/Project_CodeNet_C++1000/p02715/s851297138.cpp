#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	int n,k;
	cin>>n>>k;

	vector<ll> factor(k+1,1);
	// repi(i,1,k+1) factor[i] = power(i,n);

	ll ans=0;
	repr(i,k,1){
		factor[k/i] = power(k/i,n);
		ll tmp = factor[k/i];
		repi(j,2,k+1){
			if(i*j>k)break;
			tmp -= factor[k/(i*j)];
			tmp += mod;
			tmp %= mod;
		}
		
		ans+=(i*tmp)%mod;
		ans%=mod;

		factor[k/i] = tmp;
	}

	// repi(i,1,k+1)cout<<i<<" "<<factor[i]<<endl;

	cout<<ans<<endl;

	return 0;
}