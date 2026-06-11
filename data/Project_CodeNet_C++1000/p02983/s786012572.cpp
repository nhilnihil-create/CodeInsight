#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int L, R;
	cin >> L >> R;
	int ans = 2018;
	bool ok = true;
	for (int i = L; i < R; i++){
		for (int j = i + 1; j <= R; j++){
			ans = min(((i%2019)*(j%2019))%2019, ans);
			if (ans == 0) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	cout << ans << endl;
	return 0;
}
