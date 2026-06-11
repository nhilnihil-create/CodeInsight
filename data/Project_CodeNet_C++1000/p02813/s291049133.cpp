#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int solve(vector<int> v, const vector<int> P) {
	int cnt = 0;
	while (v != P) {
		next_permutation(v.begin(), v.end());
		cnt++;
	}
	return cnt;
}

int main() {
	int N;
	cin >> N;
	vector<int> P(N), Q(N);
	rep(i, N) {
		cin >> P.at(i);
	}
	rep(i, N) {
		cin >> Q.at(i);
	}
	vector<int> v(N);
	rep(i, N)v.at(i) = i + 1;

	cout << abs(solve(v, P) - solve(v, Q)) << endl;
}
