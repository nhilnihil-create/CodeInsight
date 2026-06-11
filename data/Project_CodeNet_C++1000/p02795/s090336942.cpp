#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w, n; cin >> h >> w >> n;
	int m = max(h, w);
	cout << (n + m - 1) / m << endl;
	return 0;
}