#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, m; cin >> n >> m;
	int N = (n * (n - 1)) / 2;
	int M = (m * (m - 1)) / 2;
	cout << N + M << endl;
}
