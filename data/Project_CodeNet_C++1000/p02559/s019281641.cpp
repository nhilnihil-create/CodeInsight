#include <iostream>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main() {
	int N, Q;
	cin >> N >> Q;
	fenwick_tree<long long> fw(N);
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		fw.add(i, a);
	}
	for (int q = 0; q < Q; q++) {
		int s;
		long long a, b;
		cin >> s >> a >> b;
		if (s == 0) fw.add(a, b);
		else cout << fw.sum((int)a, (int)b) << endl;
	}
}
