#include <iostream>
#include <set>
using namespace std;

int max_in_set(multiset<int> &st) {
	return *st.rbegin();
}

bool erase_max(multiset<int> &st) {
	if (st.empty()) return false;
	st.erase(--st.end());
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		st.insert(a);
	}
	for (int i = 0; i < m; i++) {
		int x = max_in_set(st);
		erase_max(st);
		st.insert(x/2);
	}
	long long ans = 0;
	for (int x : st) {
		ans += x;
	}
	cout << ans << endl;
	return 0;
}