// https://leetcode.com/problems/count-complete-tree-nodes/

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i=0; i < (int)n; i++)
#define fora(x, arr) for(auto& x:arr)
using matrix = std::vector<vector<int>>;
using ll = long long;


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	ll a, b; cin >> a >> b;
	ll m;
	if (a > b) 
		m = a;
	else 
		m = b;

	ll x = abs(a-b);
	ll z = x >> 1;

	for (ll i = z; i <= (x+m); i++) {

		if (abs(a-i) == abs(b-i)) {
			cout << i;
			return 0;
		}

	}

	cout << "IMPOSSIBLE";
    return 0;
}