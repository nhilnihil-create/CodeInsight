#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int findSum(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}
	return sum;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	string s;
	cin >> s;
	if (findSum(s) % 9 == 0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

