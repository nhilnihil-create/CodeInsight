#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	string s;
	cin >> s;
	int i = 0, j = n - 1, count = 0;
	while (i < j) {
		if (s[i] == 'W' && s[j] == 'R') {
			swap(s[i], s[j]);
			count++;
			i++, j--;
		}
		if (s[i] == 'R')
			i++;
		if (s[j] == 'W')
			j--;
	}
	cout << count;
	return 0;
}