#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int k, x; cin >> k >> x;
	string ans = "No";
	if (x <= 500 * k) ans = "Yes";
	cout << ans << endl;
    return 0;
}