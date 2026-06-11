#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define fi first
#define se second
#define FF first
#define SS second
#define mp make_pair
#define ll long long
#define int long long
#define pii pair<ll,ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(x) (int)x.size()
typedef long double f80;
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

ll pwr(ll a, ll b) {
    a %= mod;
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

const int N = 2e5 + 5;

int a[N], b[N];

set<int> s;
int n;

void check(int idx) {
    int i1 = (idx - 1 + n) % n;
    int i2 = (idx + 1 + n) % n;
    if(a[i1] + a[i2] < a[idx] && a[idx] != b[idx])
        s.insert(idx);
}

signed main()
{
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    fr(i, 0, n - 1) {
        cin >> b[i];
    }
    fr(i ,0, n - 1) {
        cin >> a[i];
    }
    fr(i, 0, n - 1) {
        int i1 = (i - 1 + n) % n;
        int i2 = (i + 1 + n) % n;
        if(a[i1] + a[i2] < a[i] && a[i] != b[i]) {
            s.insert(i);
        }
    }
    ll ans = 0;
    while(!s.empty()) {
        int idx = *s.begin();
        s.erase(s.begin());
        if(a[idx] == b[idx]) continue;
        int i1 = (idx - 1 + n) % n;
        int i2 = (idx + 1 + n) % n;
        int val = a[i1] + a[i2];
        if(a[idx] < b[idx]) return cout << -1, 0;
        int rem = a[idx] % val;
        if(b[idx] <= rem) {
            ans += a[idx] / val;
            a[idx] = rem;
        }
        else {
            int k = (a[idx] - b[idx]);
            if(k % val != 0) {
                return cout << -1, 0;
            }
            k /= val;
            ans += k;
            a[idx] -= k * val;
        }
        check(i1);
        check(i2);
    }
    fr(i, 0, n - 1) {
        if(a[i] != b[i]) {
            return cout << -1, 0;
        }
    }
    cout << ans;
    return 0;
}