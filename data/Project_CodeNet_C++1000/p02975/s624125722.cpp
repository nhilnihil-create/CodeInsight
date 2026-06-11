#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num;
map<int, int>mp;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int x = 0;
	for (auto it : mp) {
		x ^= it.first;
		num++;
	}
	if (num == 1) {
		cout <<( mp[0] == n ? "Yes\n" : "No\n");
	}
	else if (n % 3 != 0) {
		cout << "No" << '\n';
	}
	else if (num == 2) {
		if (mp[0] == n / 3) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	else if (num == 3 && x == 0) {
		for (auto it : mp) {
			if (it.second != n / 3) { puts("No"); return 0; }
		}
		puts("Yes");
	}
	else cout << "No" << '\n';
}


