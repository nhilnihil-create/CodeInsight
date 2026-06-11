#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string s; int  q; cin >> s >> q;
	bool standard = true;
	string right = "";
	string left = "";
	for (int i = 0; i < q; i++) {
		int t; cin >> t;		
		if (t == 2) {
			int f; char c; cin >> f >> c;
			string sc{ c };
			if (standard) {
				if (f == 1) {
					left = sc + left;
				}
				else { // t == 2
					right += sc;
				}
			}
			else {
				if (f == 1) {
					right += sc;
				}
				else { // t == 2
					left = sc + left;
				}
			}
		}
		else { // t == 1
			if (standard) standard = false;
			else standard = true;
		}
	}
	s = left + s;
	s += right;
	if (!standard) reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}