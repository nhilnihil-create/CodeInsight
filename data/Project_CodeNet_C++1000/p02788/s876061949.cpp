#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int N;
ll D, A;
vector<ll> X, H;

ll solve()
{
    vector<int> idx(N);
    rep(i, N) idx[i] = i;
    sort(idx.begin(), idx.end(), [](int i, int j) { return X[i] < X[j]; });
    vector<ll> NX(N), NH(N);
    rep(i, N) NX[i] = X[idx[i]], NH[i] = H[idx[i]];
    X = NX, H = NH;

    vector<ll> IMOS(N + 1, 0); //[N]は飛び出した時のため
    ll res = 0;
    rep(i, N)
    {
        if (IMOS[i] < H[i])
        {
            ll need = (H[i] - IMOS[i] - 1) / A + 1;
            ll right = X[i] + 2 * D;
            int r_id = upper_bound(X.begin(), X.end(), right) - X.begin();

            IMOS[i] += need * A;
            IMOS[r_id] -= need * A;

            res += need;
        }
        IMOS[i + 1] += IMOS[i];
    }
    return res;
}

int main()
{
    cin >> N >> D >> A;
    X.resize(N);
    H.resize(N);
    rep(i, N) cin >> X[i] >> H[i];
    cout << solve() << endl;
}