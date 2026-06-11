#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
 
int main() {
	FASTIO

	int n, x, t;
	cin >> n >> x >> t;
	int ans = ((n/x) + (n%x != 0))*t;
	cout << ans << "\n";
	
	return 0;
}