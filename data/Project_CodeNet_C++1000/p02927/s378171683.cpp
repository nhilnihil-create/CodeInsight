#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define chmin(x,y) x = min(x,y)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const ll MOD = 1e9+7;

int main() {
	int M, D;
	cin >> M >> D;

    int ans = 0;
    for (int i = 22; i <= D; i++) {
        int d1 = i % 10; if (d1 < 2) continue;
        int d10 = i / 10; if (d10 < 2) continue;
        if (d1 * d10 <= M) ans++;
    }

	cout << ans << endl;
	return 0;
}
