#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

int m[500][500];

void solve(int mn, int mx, int v) {
	int X = mx - mn + 1;
	if (X == 1) {
		return;
	}
	if (X == 2) {
		m[mn][mx] = v;
		m[mx][mn] = v;
		return;
	}
	int md = (mn + mx) / 2;
	
	for (int i = mn;i <= md;i++) {
		for (int j = md + 1;j <= mx;j++) {
			m[i][j] = v;
			m[j][i] = v;
		}
	}

	solve(mn, md, v + 1);
	solve(md + 1, mx, v + 1);
}

int main(){
	int N;
	cin >> N;
	solve(1, N, 1);

	for (int i = 1;i < N;i++) {
		for (int j = i + 1;j <= N;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}