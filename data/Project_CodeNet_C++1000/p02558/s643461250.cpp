#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define STRING(str) #str

template <typename T >
void print_vec_1d(vector<T> x, string name) {
	cout << name << endl;
	cout << "[ ";
	for (int i=0;i<x.size();i++) {
		cout << x[i];
		if (i != x.size()-1) cout << ", ";
		else cout << " ]" << endl;
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	dsu d(N);
	for (int i=0;i<Q;i++) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
			d.merge(u, v);
		} else { // t == 1
			cout << d.same(u, v) << endl;
		}
	}
}