#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int d[n];
    for (int i = 0; i < n; ++i) cin >> d[i];
    sort(d, d + n);
    int ans = 0;
    for (int i = d[n / 2 - 1] + 1; i <= d[n / 2]; ++i) ++ans;
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/