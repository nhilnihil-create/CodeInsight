#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(0);
	int k, ans[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	cin >> k;
	cout << ans[k - 1] << "\n";
	return 0;
}
