#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
typedef long double lld;
const ll INF = 1e18;
const ll MOD = 1e9+7;
 
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
 
ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}

ll mul(ll a,ll b){
	return (a*(b+MOD)%MOD)%MOD;
}

void solve(){
	ll n;
	cin>>n;
	vector< pair<ll,ll> > robot;
	
	for(ll i=0;i<n;i++){
		ll x,l;
		cin>>x>>l;
		robot.pb(mk(x+l,x-l));
	}
	
	sort(robot.begin(),robot.end());
	ll ans = 0;
	ll prev = INT_MIN;
	for(ll i=0;i<n;i++){
		if(robot[i].se>=prev){
			ans++;
			prev = robot[i].fi;
		}
	}
	cout<<ans<<"\n";
	
}



int main(){
    fastio;
    int t;
    t = 1;
    //cin>>t;
    
    for(int i=1;i<=t;i++)
	solve();
	
}


