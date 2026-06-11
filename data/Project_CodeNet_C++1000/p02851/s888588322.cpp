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

static const long long MOD = 1000000007;
static const long long INF = 1<<31;

ll ans, a[200005], s, k, r[200005];
map<ll, ll> m;
int n;

int main(void) {
  cin >> n >> k;
  rep(i, 1, n+1) scanf("%lld", &a[i]);
  m[0]++;
  rep(i, 1, n+1) {
    if (i>=k) m[r[i-k]]--;
    s += a[i];
    ll t = (s - i)%k;
    if (t<0) t += k;
    //cout << t << endl;
    ans += m[t];
    m[t]++;
    r[i] = t;
  }
    
    cout << ans << "\n";

    return 0;
}

