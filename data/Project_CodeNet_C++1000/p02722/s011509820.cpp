#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int maxn = 1e5+10;
const int mod = 1e9+7;

using namespace std;

void solve(){
	ll n;
	cin>>n;
	int ans=0;
	set<ll> divisores;
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			divisores.insert(i);
			divisores.insert(n/i);
		}
	}
	--n;
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			divisores.insert(i);
			divisores.insert(n/i);
		}
	}
	++n;
	for(ll x:divisores){
		//cout<<"x="<<x<<endl;
		if(x==1) continue;
		ll aux = n;
		while(aux%x==0)
			aux/=x;
		if(aux%x==1)
			++ans;
	}
	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}