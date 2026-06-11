#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ar array
#define vi vector<int>
#define vll vector<ll>
#define vpl vector<pair<ll, ll>> 
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

void init() {
	
}

void solve() {
	int x; cin >> x;
	if (x >= 400 && x < 600) cout << "8";
	else if (x >= 600 && x < 800) cout << "7";
	else if (x >= 800 && x < 1000) cout << "6";
	else if (x >= 1000 && x < 1200) cout << "5";
	else if (x >= 1200 && x < 1400) cout << "4";
	else if (x >= 1400 && x < 1600) cout << "3";
	else if (x >= 1600 && x < 1800) cout << "2";
	else if (x >= 1800 && x < 2000) cout << "1";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int t = 1; 
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}