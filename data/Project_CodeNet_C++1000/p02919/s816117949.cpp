#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    ll N;
    cin >> N;
    vector<ll> P(N);
    vector<pair<ll, ll>> Q(N);
    rep(i, N)
    {
        cin >> P[i];
        Q[i] = make_pair(P[i], i);
    }

    sort(Q.rbegin(), Q.rend());

    set<ll> st;

    ll ans = 0;

    rep(j, N)
    {
        ll p = Q[j].first;
        ll i = Q[j].second;

        st.insert(i);
        if (j == 0) {
            continue;
        }

        auto i_it = st.lower_bound(i);
        auto b1_it = next(i_it, 1);
        auto b2_it = next(i_it, 2);
        auto a1_it = prev(i_it, 1);
        auto a2_it = prev(i_it, 2);

        ll b1, b2, a1, a2;
        if (b1_it == st.end()) {
            b1 = N;
        } else {
            b1 = *b1_it;
        }

        if (b2_it == st.end() || b1 == N) {
            b2 = N;
        } else {
            b2 = *b2_it;
        }

        if (i_it == st.begin()) {
            a1 = -1;
        } else {
            a1 = *a1_it;
        }

        if (a1_it == st.begin() || a1 == -1) {
            a2 = -1;
        } else {
            a2 = *a2_it;
        }

        ans += ((a1 - a2) * (b1 - i) + (i - a1) * (b2 - b1)) * p;
    }

    cout << ans << endl;

    return 0;
}