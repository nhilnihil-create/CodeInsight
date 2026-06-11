#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int A, B; cin >> A >> B;
	double inf, sup;

	inf = max((double)A / 0.08, (double)B / 0.1);
	sup = min((double)(A + 1) / 0.08, (double)(B + 1) / 0.1);

	int ans = ceil(inf);
	if (ans >= sup)cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}