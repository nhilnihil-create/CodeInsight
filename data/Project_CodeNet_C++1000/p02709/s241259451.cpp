#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pll> a(n);
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        a[i] = mp(h,i);
    }
    sort(all(a));
    reverse(all(a));

    vector<vll> dp(n + 1, vll(n + 1, -(1LL << 50)));
    dp[0][0] = 0;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(dp[i][j] == -(1LL << 50)) continue;
            int right = i - j + 1;
            // lets go left
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i].first*abs(a[i].second - j));
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i].first*abs(n - right - a[i].second));
        }
    }
    ll ans = -1;
    for(int i = 0; i < n + 1; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
