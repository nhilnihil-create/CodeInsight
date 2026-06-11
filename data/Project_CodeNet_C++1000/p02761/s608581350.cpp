#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
//setprecision(15)

int main() {
	int N, M; cin >> N >> M;
	vector<int> v(N, -1);
	int s, c;
	rep(i, M) {
		cin >> s >> c;
		if ((N > 1) && (s == 1) && (c == 0)) goto ERR_END;
		if (v[s-1] != -1 && v[s-1] != c) goto ERR_END;
		v[s-1] = c;
	}
	rep(i, N) {
		if (v[i] != -1) continue;
		if (i == 0) {
			if (N == 1) v[i] = 0;
			else v[i] = 1;
		} else {
			v[i] = 0;
		}
	}
	rep(i, N) cout << v[i];
	cout << endl;
	return 0;
ERR_END:
	cout << "-1" << endl;
	return 0;
}