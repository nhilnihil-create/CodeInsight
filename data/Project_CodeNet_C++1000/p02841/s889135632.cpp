#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string m1, d1, m2, d2; cin >> m1 >> d1 >> m2 >> d2;
	int ans;
	if (d2.size() == 1 && d2 == "1") {
		ans = 1;
	}
	else ans = 0;
	cout << ans << endl;
    return 0;
}