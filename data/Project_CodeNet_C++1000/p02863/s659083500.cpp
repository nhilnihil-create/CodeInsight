#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

const int INF = 1e9;
int dp[6100];

int main()
{
    //freopen("testCase.txt", "r", stdin);

    int n, t;
    cin >> n >> t;

    //cout << -INF << '\n';

    memset(dp, -INF, sizeof(dp));
    dp[0] = 0LL;

    vpii v(n);

    for(int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = mp(a, b);
    }

    sort(all(v));

    for(int i = 0; i < n; ++i)
    {
        int a = v[i].fi, b = v[i].se;

        for(int j = t-1; j >= 0; --j)
        {
            if(dp[j] != -INF)
            {
                dp[j+a] = max(dp[j+a], dp[j] + b);
            }
        }
    }

    int najveci = -INF;

    for(int i = 0; i < 6100; ++i)
    {
        najveci = max(najveci, dp[i]);
    }

    cout << najveci << '\n';

    return 0;
}
