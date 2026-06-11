#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll n, k;
vector<ll> ara;

bool is_ok(ll mid)
{
    ll kk = k;
    ll total = 0;

    if (mid == 0)
        return false;

    for (ll i = 0; i < n; i++)
    {
        if (ara[i] <= mid)
            continue;

        int t = ara[i] / mid;
        kk -= t;
    }

    return (kk >= 0);
}

ll bin_srch()
{
    ll lo = 0, hi = 1e9 + 10, mid;

    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;

        if (is_ok(mid))
        {
            hi = mid;
        }

        else
        {
            lo = mid + 1;
        }
    }

    return lo;
}

int main()
{
    cin >> n >> k;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        ara.push_back(x);
    }

    cout << bin_srch() << endl;

    return 0;
}