#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
	int n, m;
	cin >> n >> m;

	if (n<=m) {
		for (int i = 0; i < m;i++) {
			cout << n;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << m;
		}
	}

	

	return 0;
}
