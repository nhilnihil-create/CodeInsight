#include<bits/stdc++.h>
using namespace std;


#define rep(i, n) for(int i = 0; i < (n); i++)
using ULL = unsigned long long;


int lev(int a, int b) {
	int ans = 1; int buf = a ^ b;
	while ((buf & 1) == 0) {
		ans++;
		buf >>= 1;
	}
	return ans;
}


void solve() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << lev(i, j);
			if (j != n - 1) cout << " ";
		}
		cout << endl;
	}
}

int main() {

	solve();

	return 0;
}