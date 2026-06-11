#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using p = pair<int, int>;
using ll = long long;

int main()
{
    int n,k;
    cin >> n >> k;

    vector<ll> h(n);
    rep(i, n) cin >> h.at(i);

    sort(h.rbegin(), h.rend());

    ll ans = 0;
    rep2(i, k, n) {
        ans += h.at(i);
    }
    cout << ans << endl;
    return 0;
}