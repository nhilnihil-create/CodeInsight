#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

int main() {
	ll a, b, v, w, t;
	cin >>a>>v>>b>>w>>t;
	if (a == b) {
		cout <<"YES\n";
	} else if (v <= w) {
		cout <<"NO\n";
	} else {
		ll x = (v-w)*t;
		if (x >= abs(a-b)) cout <<"YES\n";
		else cout <<"NO\n";
	}
	return 0;
}