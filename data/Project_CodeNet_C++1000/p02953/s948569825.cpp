#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 5;

int n;
int h[N];

int main() {
	//freopen(".inp", "r", stdin); freopen(".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	h[1]--;
	for (int i = 2; i <= n; i++) {
		if (h[i] > h[i - 1]) {
			h[i]--;
		}
	}
	bool ok = true;
	for (int i = 1; i < n; i++)
		if (h[i] > h[i + 1]) {
			ok = false;
			break;
		}
	if (ok) cout << "Yes";
	else cout << "No";
	return 0;
}
