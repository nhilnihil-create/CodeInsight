#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll W,H,x,y;
	cin >> W >> H >> x >> y;

	cout << fixed << setprecision(15);
	cout << (double)W * H / 2 << " ";

	if(W == 2 * x && H == 2 * y){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
	}

	return 0;
}