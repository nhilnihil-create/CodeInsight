#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n, m;
pair <int, int> a[105];
bool correct;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	if (n == 1) {
		for(int i = 0; i < 10; ++i) {
			correct = true;
			string s = to_string(i);
			for(int j = 0; j < m; ++j) {
				if ((int)(s[a[j].first-1])-48 != a[j].second) {
					correct = false;
				}
			}
			if (correct == true) {
				cout << s;
				return 0;
			}
		}
	}
	else if (n == 2) {
		for(int i = 10; i < 100; ++i) {
			correct = true;
			string s = to_string(i);
			for(int j = 0; j < m; ++j) {
				if ((int)(s[a[j].first-1])-48 != a[j].second) {
					correct = false;
				}
			}
			if (correct == true) {
				cout << s;
				return 0;
			}
		}
	}
	else if (n == 3) {
		for(int i = 100; i < 1000; ++i) {
			correct = true;
			string s = to_string(i);
			for(int j = 0; j < m; ++j) {
				if ((int)(s[a[j].first-1])-48 != a[j].second) {
					correct = false;
				}
			}
			if (correct == true) {
				cout << s;
				return 0;
			}
		}
	}
	cout << -1;
}