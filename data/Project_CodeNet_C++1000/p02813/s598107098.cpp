#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> P(N), Q(N);
	for (int &e : P) {
		cin >> e;
	}
	for (int &e : Q) {
		cin >> e;
	}
	vector<int> perm(N);
	vector<vector<int>> perms;
	iota(begin(perm), end(perm), 1);
	do {
		perms.push_back(perm);
	} while (next_permutation(begin(perm), end(perm)));
	auto itp = lower_bound(perms.begin(), perms.end(), P);
	auto itq = lower_bound(perms.begin(), perms.end(), Q);
	cout << abs(distance(itp, itq)) << endl;
}