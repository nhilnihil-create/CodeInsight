#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

ll dfs(ll val) {
    if (val == 1) {
        return 1;
    }

    ll cnt = 1;

    cnt += (2 * dfs(val / 2));

    return cnt;
}

int main() {
    ll H;
    cin >> H;

    cout << dfs(H) << endl;
}
