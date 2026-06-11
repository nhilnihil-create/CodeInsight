#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define INF INT_MAX

int main() {
	int A, B, M;
	int a[MAX], b[MAX];
	int mina = INF, minb = INF;
	int ans;
	cin >> A >> B >> M;
	for (int i = 0; i < A; i++) {
		cin >> a[i];
		mina = min(mina, a[i]);
	}
	for (int i = 0; i < B; i++) {
		cin >> b[i];
		minb = min(minb, b[i]);
	}
	ans = mina + minb;
	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		ans = min(ans, a[x - 1] + b[y - 1] - c);
	}
	cout << ans << endl;
	return 0;
}
