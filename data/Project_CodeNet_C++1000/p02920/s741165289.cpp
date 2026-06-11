#include <bits/stdc++.h>
using namespace std;
multiset<int> st;
vector<int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp;
	cin >> n;
	int bound = 1 << n;
	for (int i = 0; i < bound; ++i) {
		cin >> tmp;
		st.insert(-1 * tmp);
	}
	bool flag = true;
	vec.push_back(*st.begin());
	st.erase(st.begin());
	while (!st.empty() && flag) {
		vector<int> newv;
		for (int i = 0; i < vec.size() && flag; ++i) {
			auto ptr = st.upper_bound(vec[i]);
			if (ptr == st.end())
				flag = false;
			else {
				newv.push_back(*ptr);
				st.erase(ptr);
			}
		}
		for (int i = 0; i < newv.size(); ++i)
			vec.push_back(newv[i]);
		sort(vec.begin(), vec.end());
	}
	if (flag)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}