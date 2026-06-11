#include<bits/stdc++.h>
using namespace std;
const int MX = 2005;

typedef long long ll;

#define f first
#define s second

int N;
vector<pair<ll,int>> v; // happiness, position
ll dp[MX][MX];

ll solve_dp(int l, int r) {
    if (r < l) return 0;
    ll& res = dp[l][r];
    if (res != -1) return res;
    int pos = l+N-1-r;
    res = max(res,v[pos].f*abs(l-v[pos].s)+solve_dp(l+1,r));
    res = max(res,v[pos].f*abs(r-v[pos].s)+solve_dp(l,r-1));
    return res;
}

int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N; v.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i].f; v[i].s = i;

        for (int j = 0; j < N; ++j) {
            dp[i][j] = -1;
        }
    }

    sort(v.rbegin(),v.rend());

    cout << solve_dp(0,N-1) << "\n";

}
