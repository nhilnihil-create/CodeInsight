#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	string sa = "";
	for (int i = 0; i < b; i++) {
		sa += to_string(a);
	}
	string sb = "";
	for (int i = 0; i < a; i++) {
		sb += to_string(b);
	}
	string ans;
	if (a < b) ans = sa;
	else ans = sb;
	cout << ans << endl;
    return 0;
}