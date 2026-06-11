#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
int main() {
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) v[i] = i+1;
	vector<int> p(N), q(N);
	rep(i, N) cin >> p[i];
	rep(i, N) cin >> q[i];
	int n_p, n_q;
	int cnt = 0;
	do {
		cnt++;
		if (v == p) n_p = cnt;
		if (v == q) n_q = cnt;
	} while (next_permutation(v.begin(), v.end()));
	int ans = max(n_p-n_q, n_q-n_p);
	cout << ans << endl;
}