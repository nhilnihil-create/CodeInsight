#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i = (int)(begin); i < (int)(end); i++)
#define rep(i, n) FOR(i, 0, n)
using ll = long long;
using namespace std;
using P = pair<int, int>;


ll d[5002];
ll dm[5002];

int main(int argc, char const *argv[])
{
    int k, q;
    cin >> k >> q;
    rep(i, k) {
        cin >> d[i];
    }
    rep(i, q) {
        ll n, x, m;
        cin >> n >> x>>m;
        ll nn = n-1;
        rep(j, k) {
            dm[j] = d[j] % m;
        }
        x %= m;
        int n_0 = 0;
        rep(j, k) {
            if(dm[j] == 0) n_0++;
        }
        n_0 *= nn / k;
        rep(j, nn%k) {
            if(dm[j] == 0) n_0++;
        }
        ll a_nm1 = x;
        for (int j = 0; j < nn%k; j++)
        {
            a_nm1 += dm[j] * (nn/k+1);
        }
        for(int j= nn%k; j<k; j++) {
            a_nm1 += dm[j] * (nn/k);
        }
        int ans = a_nm1 / m - x/ m;
        ans = (n-1) - n_0 - ans;
        cout << ans << endl;
    }

    return 0;
}
