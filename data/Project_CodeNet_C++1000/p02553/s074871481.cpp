/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll ans;
	ans = max(a*c,b*d);
	ans = max(ans,a*d);
	ans = max(ans,b*c);
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
