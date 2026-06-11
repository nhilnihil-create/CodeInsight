#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(0);
	int a, b;
	cin >> a >> b;
	int ans = a + b;
	if (ans % 2 == 0) cout << ans / 2 << "\n";
	else cout << "IMPOSSIBLE" << "\n";
	return 0;
}
