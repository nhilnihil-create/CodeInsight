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
    ll ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=i; j<=n; j+=i) {
            ans += j;
        }
    }
    cout << ans << endl;
    return 0;
}