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
	fenwick_tree<long long> fw(N);
	for (int i=0;i<N;i++) {
		long long a;
		cin >> a;
		fw.add(i, a);
	}
	for (int i=0;i<Q;i++) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			fw.add(p, x);
		} else { // t == 1
			int l, r;
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}
}