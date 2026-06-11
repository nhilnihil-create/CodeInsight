#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	const int p = 5;
	vector<int> x(p);
	for (int i = 0; i < p; i++) {
		cin >> x[i];
	}
	int ans;
	for (int i = 0; i < p; i++) {
		if (x[i] == 0) ans = i + 1;
	}
	cout << ans << endl;
    return 0;
}