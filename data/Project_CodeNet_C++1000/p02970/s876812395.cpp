#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n, d;
	cin >> n >> d;
	int ans = n  / ((d * 2) + 1);
	if (n % ((d * 2) + 1) != 0) {
		ans++;
	}
	cout << ans;
}

















