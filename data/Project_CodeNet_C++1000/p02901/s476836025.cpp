//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 500 + 5;
const int M = 1e3 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int n,m,a[M],b,x,dp[M][1<<12];
vector<int> c[M];

int solve(int idx, int mask) {

    if(idx == m) return mask == (1 << n) - 1 ? 0 : OO;

    int &ret = dp[idx][mask];

    if(~ret) return ret;

    ret = OO;

    ret = min(ret, solve(idx+1, mask));

    int newMask = mask;

    for(auto bit: c[idx]) {

        newMask |= (1 << (bit-1));

    }

    ret = min(ret, solve(idx+1, newMask) + a[idx]);

    return ret;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b;
        for (int j = 0; j < b; ++j) {
            cin >> x;
            c[i].pb(x);
        }
    }

    memset(dp, -1, sizeof dp);

    int ans = solve(0, 0);

    cout << (ans == OO ? -1 : ans) << '\n';

    return 0;
}