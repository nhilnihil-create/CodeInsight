#include <bits/stdc++.h>

using namespace std;

int count(int n) {
	int ans = 1;
	int cur = 7;
	while (cur % n != 0) {
		cur = (cur * 10 + 7) % n;
		ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0 || n % 5 == 0) {
		cout << -1 << endl;
	} else {
		cout << count(n) << endl;
	}
}
