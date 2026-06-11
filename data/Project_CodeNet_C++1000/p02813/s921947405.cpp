#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string p_s = " ";
	string q_s = " ";
	for (int i = 0; i < n; i++) {
		string p; cin >> p;
		p_s += p;
	}
	for (int i = 0; i < n; i++) {
		string q; cin >> q;
		q_s += q;
	}
	vector<int> c(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		c[i] = i + 1;
	}
	int a, b;
	do {
		cnt++;
		// c[i] を使う
		string tmp = " ";
		for (int i = 0; i < c.size(); i++) {
			tmp += to_string(c[i]);
		}
		if (tmp == p_s) a = cnt;
		if (tmp == q_s) b = cnt;

	} while (next_permutation(c.begin(), c.end()));
	cout << abs(a - b) << endl;
    return 0;
}