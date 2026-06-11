#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {
  /**
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  **/
	FIO
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0, k = 1;
    for (int i = 0; i < n; i++) {
    	if (a[i] == k) k++;
    	else ans++;
    }
    if (ans == n) cout << -1 << "\n";
    else cout << ans << "\n"; 
    return 0;
}