/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){
	int n;
	cin >> n;
	vector < vector <ll> > v(4,vector <ll> (n));
	for(ll i=0;i<n;i++){
		ll x,y;
		cin >> x >> y;
		v[0][i] = x+y;
		v[1][i] = x-y;
		v[2][i] = -x+y;
		v[3][i] = -x-y;
	}
	ll ans = 0;
	for(ll i=0;i<4;i++){
		sort(v[i].begin(),v[i].end());
		ans = max(v[i].back()-v[i].front(),ans);
	}
	cout << ans << endl;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int z;
	z = 1;
	//cin >> z;
	for(int z1=1;z1<=z;z1++){
		solve();
	}
	return 0;
}
