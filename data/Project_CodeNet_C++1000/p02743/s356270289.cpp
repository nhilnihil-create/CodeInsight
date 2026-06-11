#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll a, b, c;
	cin >> a >> b >> c;

	ll d = c - a - b;
	if (d>0 && d*d > 4*a*b){
			cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}