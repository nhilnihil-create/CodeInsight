#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		a.at(i) -= i;
	}
	map<int, int>st;
	st[0 - a.at(0)] = 1;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (st.count(a.at(i)))ans += st.at(a.at(i));
		int x = 0 - (a.at(i)+i)-i;
		if (st.count(x))st.at(x)++;
		else st[x] = 1;
	}
	cout << ans << endl;
}