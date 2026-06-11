#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
#define MAX_N 100000
int main() {
	int N; cin >> N;
	vector<P> v(N);
	rep(i, N) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	rep(i, N) {
		cout << v[i].second;
		if (i == N - 1) cout << endl;
		else cout << " ";
	}
}