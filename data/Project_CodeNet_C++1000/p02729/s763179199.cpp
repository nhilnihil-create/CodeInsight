#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m; cin >> n >> m;
  	cout << n * (n - 1) / 2 + m * (m - 1) / 2 << endl;
  	return 0;
}
