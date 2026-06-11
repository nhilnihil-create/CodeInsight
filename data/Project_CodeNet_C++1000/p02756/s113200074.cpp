#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	string s;
	int q;
	int t, f;
	bool b = false;
	string c;
	cin >> s;
	cin >> q;
	rep(i, q) {
		cin >> t;
		if (t == 1) {
			if (b == false)b = true;
			else b = false;
		}
		else {
			cin >> f >> c;
			if ((f == 1 && b == false) || (f == 2 && b == true))s.insert(0, c);
			else s.insert(s.length(), c);
		}
	}
	if (b == true)reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}