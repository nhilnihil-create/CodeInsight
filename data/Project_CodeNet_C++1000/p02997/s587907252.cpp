#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    scanf("%d %d", &n, &k);
    vector <pair <int, int> > ans;
    for (int i = 2; i <= n; i++) {
		ans.pb({1, i});
		k -= i - 2;
	}
	for (int i = 2; i <= n && k < 0; i++) {
		for (int j = i + 1; j <= n && k < 0; j++, k++) {
			ans.pb({i, j});
		}
	}
	if (k != 0) {
		printf("-1");
	} else {
		printf("%d\n", (int)ans.size());
		for (auto x : ans) {
			printf("%d %d\n", x.fi, x.se);
		}
	}
    return 0;
}
