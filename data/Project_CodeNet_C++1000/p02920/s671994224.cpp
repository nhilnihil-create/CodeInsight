#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	multiset<int, greater<int>> st, cur;
	for(int i=0; i<(1<<n); i++) {
		int t;
		cin >> t;
		st.insert(t);
	}
	cur.insert(*st.begin());
	st.erase(st.begin());
	while(st.size()) {
		vector<int> v;
		for(int c: cur) {
			auto it = st.upper_bound(c);
			if(it == st.end())
				return !(cout << "No");
			v.push_back(*it);
			st.erase(it);
		}
		cur.insert(v.begin(), v.end());
	}
	cout << "Yes";
}