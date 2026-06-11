#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

ll dp[2];
ll ndp[2];
void solve() {
	string s;
	cin >> s;
	reverse(all(s));
	s += "0";
	dp[1] = 1e18;
	for(int i = 0; i < sz(s); i++) {
		ndp[0] = 1e18;
		ndp[1] = 1e18;
		int need = s[i] - '0';
		// if you paid exact before
		// pay exact now
		ndp[0] = min(ndp[0], dp[0] + need);
		// receive change for this one
		ndp[1] = min(ndp[1], dp[0] + (10 - need));
		// if you accepted one above
		need++;
		ndp[0] = min(ndp[0], dp[1] + need);
		ndp[1] = min(ndp[1], dp[1] + (10 - need));
		dp[0] = ndp[0];
		dp[1] = ndp[1];
	}
	cout << dp[0] << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
