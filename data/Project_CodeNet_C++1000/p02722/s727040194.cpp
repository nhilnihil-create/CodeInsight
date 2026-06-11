#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mxn = 1e5;
// int cnt1[mxn+2],cnt2[mxn+2];

void solve(){
	ll n,cpyn;
	cin >> n;
	cpyn=  n;
	vi divn;
	divn.pb(n);
	vi divn1;
	divn1.pb(n-1);

	for(ll i =2;i*i<=n;i++){
		if(n%i==0){
			divn.pb(i);
			if(i*i!=n)
				divn.pb(n/i);
		}
	}
	n--;
	for(ll i =2;i*i<=n;i++){
		if(n%i==0){
			divn1.pb(i);
			if(i*i!=n)
				divn1.pb(n/i);
		}
	}

	ll ans = 0;
	ans+=divn1.size();
	n = cpyn;
	for(auto e:divn){
		n = cpyn;
		while(n%e==0){
			n/=e;
		}
		if(n%e==1){
			// cout << e << endl;
			ans++;
		}
	}
	if(cpyn==2)
		ans--;
	cout << ans << endl;
}

int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	// int t;cin >> t;while(t--)
		solve();
}
