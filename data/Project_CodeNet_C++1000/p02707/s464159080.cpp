#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, a; cin >> n;
	vector<int> A(n, 0);
	REP1(i, n) {
		cin >> a;
		A[a - 1]++;
	}
	REP(i, n) {
		cout << A[i] << endl;
	}
}
