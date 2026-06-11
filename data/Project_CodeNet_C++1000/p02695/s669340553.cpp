#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
int n, m, q;
vector<int> seq(10, 1);
vector<int> a(50), b(50), c(50), d(50);

int solve(int cpos) {
    int sum = 0;
    if (cpos == n) {
        for (int i = 0; i < q; ++i) {
            if (seq[b[i]] - seq[a[i]] == c[i]) {
                sum += d[i];
            }
        }
        return sum;
    }
    if (cpos == 0) {
        sum = solve(1);
    } else {
        for (int i = seq[cpos - 1]; i <= m; ++i) {
            seq[cpos]=i;
            sum = max(sum, solve(cpos + 1));
        }
    }
    return sum;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }
    cout << solve(0) << "\n";
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/