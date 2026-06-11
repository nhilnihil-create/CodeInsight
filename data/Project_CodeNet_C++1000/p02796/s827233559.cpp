#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    ll n;
    cin >> n;
    vector<P> RL(n);
    rep(i, n)
    {
        ll x, l;
        cin >> x >> l;
        RL[i] = make_pair(x + l, x - l);
    }
    sort(RL.begin(), RL.end());

    ll now =-INF;
    ll ans = 0;
    rep(i, n)
    {
        if (RL[i].second >= now)
        {
            now = RL[i].first;
            ans++;
        }
    }

    cout << ans << endl;
}