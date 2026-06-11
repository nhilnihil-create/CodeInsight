#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int a = 60 * h1 + m1;
	int b = 60 * h2 + m2;
	if (b < a) {
		cout << 0;
		return 0;
	}
	cout << max(0, (b - a) - k);

}