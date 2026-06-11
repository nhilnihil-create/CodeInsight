#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull top(ull val) { return 1llu << (63llu - __builtin_clzll(val)); }

void binary_basis_insert(vector<ull>& w, ull a) {
	for (auto v : w) if (top(v) & a) a ^= v;
	if (!a) return;
	ull t = top(a);
	for (auto& v : w) if (t & v) v ^= a;
	w.push_back(a);
}

vector<ull> binary_basis(vector<ull>& w) {
	vector<ull> res;
	for (auto v : w) binary_basis_insert(res, v);
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<ull> A(N);
	ull X = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		X ^= A[i];
	}
	for (ull b = 0; b < 60; b++) if (X & (1LL << b)) {
		for (int i = 0; i < N; i++) if (A[i] & (1LL << b)) {
			A[i] -= 1LL << b;
		}
	}
	auto v = binary_basis(A);
	ull a = 0;
	for (auto val : v) {
		if ((a ^ val) > a) a ^= val;
	}
	cout << X + (a * 2) << endl;
	return 0;
}
