#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x >= k) {
			cnt++;
		}
	}
	cout << cnt;
}

















