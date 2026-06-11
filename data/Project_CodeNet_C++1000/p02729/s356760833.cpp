#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	cout << max(0, n * (n - 1) / 2) + max(0, m * (m - 1) / 2) << endl;
    return 0;
}