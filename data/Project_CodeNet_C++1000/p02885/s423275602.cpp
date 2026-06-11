#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << (2*b >= a ? 0 : a - 2*b);
	return 0;
}