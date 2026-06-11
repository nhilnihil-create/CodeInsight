#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

void solve() {
	string s; cin >> s;
	if (s[0] == '?')s[0] = 'D';
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '?') {
			s[i] = 'D';
		}
	}
	cout << s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin >> t;
	// while (t--)
	solve();


}