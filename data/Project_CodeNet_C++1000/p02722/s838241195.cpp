#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans;
// 9  3 9
//    2 4 8
bool check(ll x, ll k) {
    while (x%k==0) x /= k;
    return (x%k) == 1;
}

int main(void) {
    ll n;
    cin >> n;
    if (n==2) {
        puts("1");
        return 0;
    }
    for (ll i=1; i*i<=n-1; i++) {
        if ((n-1)%i==0) {
            if (i==1 || i*i==n-1) ans++;
            else ans += 2;
        }
    }

    for (ll i=1; i*i<=n; i++) {
        if (n%i==0) {
            if (i!=1 && check(n, i)) ans++;
            if (i*i!=n && check(n, n/i)) ans++; 
        }
    }

    cout << ans << "\n";
    return 0;
}

