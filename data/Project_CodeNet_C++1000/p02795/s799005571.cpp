#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;

	int L = max(H, W);

	int ans = (N + L - 1) / L;

	cout << ans << "\n";

	return 0;
}
