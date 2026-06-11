#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	unordered_set<int> st;
	for (int i=1; i<=n; i++) {
		st.insert(i);
	};
	for (int i=0; i<k; i++) {
		int d; cin >> d;
		for (int j=0; j<d; j++) {
			int t;
			cin >> t;
			if (st.find(t) != st.end()) {
				st.erase(t);
			}
		}
	}
	cout << st.size();
}
