#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	const int N = 1 << n;
	multiset<int> st1;
	for(int i = 0; i < N; ++i) {
		int s; cin >> s;
		st1.insert(s);
	}
	int maxi = *st1.rbegin();
	st1.erase(st1.find(maxi));
	multiset<int> st2;
	st2.insert(maxi);
	while(st1.size()) {
		multiset<int> tmp;
		for(auto i = st2.rbegin(); i != st2.rend(); ++i) {
			int s = *i;
			auto itr = st1.lower_bound(s);
			if(itr == st1.begin()) {
				cout << "No\n";
				return 0;
			}
			itr = prev(itr);
			tmp.insert(*itr);
			st1.erase(itr);
		}
		for(int i : tmp) {
			st2.insert(i);
		}
	}
	cout << "Yes\n";
	return 0;
}