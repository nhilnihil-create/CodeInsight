#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p,q,r;
	cin >> p >> q >> r;
	cout << min(min(p+q,p+r), q+r);
	return 0;
}