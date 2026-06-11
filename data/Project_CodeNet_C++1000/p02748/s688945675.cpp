#include"bits/stdc++.h"

#define INF 2000000
#define MOD 1000000007
#define rep(i, N) for(int i = 0;i < N;i++)
#define ll long long

using namespace std;

int main(void) {
	int A, B, M; cin >> A >> B >> M;
	vector<int> a(A), b(B);
	int ans = INF;

	int mina = INF, minb = INF;
	rep(i, A) {
		cin >> a[i];
		mina = min(mina, a[i]);
	}
	rep(i, B) {
		cin >> b[i];
		minb = min(minb, b[i]);
	}
	ans = min(ans, mina + minb);

	rep(i, M) {
		int x, y, c; cin >> x >> y >> c;
		x--; y--;
		ans = min(ans, a[x] + b[y] - c);
	}

	cout << ans << endl;

	return 0;
}