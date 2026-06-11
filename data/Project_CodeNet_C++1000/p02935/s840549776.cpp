#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

int main() {
	int N; cin >> N;
	priority_queue<double> q;
	rep(i, N) {
		double v; cin >> v;
		q.push(-v);
	}
	for (int i = 0; i < N-1; i++) {
		double t = q.top(); t = -t; q.pop();
		double s = q.top(); s = -s; q.pop();
		q.push(-(s+t)/2);
	}
	double ans = q.top(); cout << setprecision(15) << -ans << endl;
}