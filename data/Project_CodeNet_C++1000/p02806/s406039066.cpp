#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll inf = 1e18+5;
ll n;
pair<string, ll> playlist[55];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >>  n;
	for (ll i= 0; i< n; i++){
		string a;
		ll b;
		cin >> a >> b;
		playlist[i] = mp(a, b);
		//~ cin >> playlist[i].F >> playlist[i].S;
	}
	string sleep;
	cin >> sleep;
	ll ans = 0;
	bool check = 0;
	for (ll i = 0; i< n; i++){
		if (check)ans += playlist[i].S;
		if (playlist[i].F == sleep){
			check=1;
		}
	}
	cout  << ans;
}
