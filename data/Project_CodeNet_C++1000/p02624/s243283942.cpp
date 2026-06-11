#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO;
	
	ll n;
	cin >> n;
	vector<ll> ar(n+1);
	
	for (int i = 1; i <= n; ++i) {
		for (ll j= i; j <= n; j+= i) {
			ar[j]++;
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (i * ar[i]);
	}
	
	cout << ans;
		
	
}
