#define LOCAL

#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f

using llong = long long;
using PII = pair<int, int>;

const llong MOD = 123456789LL;
const double PI = acos(-1);

int main() {
	IOS;
	string s; cin >> s;
	string fw = "", bw = "";
	bool f = true;
	int q; cin >> q;
	while (q--) {
		int q1; cin >> q1;
		if (q1 == 1) {
			f = !f;
		}
		else {
			int q2; char c; cin >> q2 >> c;
			q2--;
			if (!q2 == f) fw += c;
			else bw += c;
		}
	}
	if (f) {
		for (int i = (int)fw.size() - 1; i >= 0; i--) {
			cout << fw[i];
		}
		cout << s;
		for (int i = 0; i < bw.size(); i++) {
			cout << bw[i];
		}
	}
	else {
		for (int i = (int)bw.size() - 1; i >= 0; i--) {
			cout << bw[i];
		}
		reverse(s.begin(), s.end());
		cout << s;
		for (int i = 0; i < fw.size(); i++) {
			cout << fw[i];
		}
	}
}