#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	multiset<int> s;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i = 1; i <= m; ++i) {
		int x = *--s.end() / 2;
		s.erase(--s.end());
		s.insert(x);

	}
	long long answer = 0;
	for (auto x : s) {
		answer += x;
	}
	cout << answer;
}