#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll LINF = 1001002003004005006LL;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = a[0];
    int tmp = n-2;
    int idx = 1;
    while(tmp > 0) {
        if (tmp == 1) {
            ans += a[idx];
            --tmp;
        }
        else {
            ans += a[idx]*2;
            ++idx;
            tmp -=2;
        }
    }
    cout << ans << endl;
    return 0;
}