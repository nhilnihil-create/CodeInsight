#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; int q; cin >> s >> q;
	bool def = true;
	string front = "";
	string rear = "";
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			if (def) def = false;
			else def = true;
		}
		else { // t == 2
			int f; char c; cin >> f >> c;
			if (!def) {
				if (f == 1) f = 2;
				else f = 1;
			}
			if (f == 1) {
				front += c;
			}
			else {
				rear += c;
			}
		}
	}
	string ans;
	reverse(front.begin(), front.end());
	ans = front;
	ans += s;
	ans += rear;
	if (!def) reverse(ans.begin(), ans.end());
	cout << ans << endl;
    return 0;
}