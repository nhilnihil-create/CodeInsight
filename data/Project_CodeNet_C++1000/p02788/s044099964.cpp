#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

void solve() {
    ll n, d, a;
    cin >> n >> d >> a;
    vector<ii> v(n);
    fori (i, 0, n) cin >> v[i].first >> v[i].second;
    sort(begin(v), end(v));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll ans = 0;
    ll to_rem = 0;
    fori (i, 0, n) {
        ll x, h;
        tie(x, h) = v[i];
        while (!pq.empty() && pq.top().first < x) {
            to_rem -= pq.top().second;
            pq.pop();
        }
        h -= a * to_rem;
        if (h > 0) {
            ll need = (h + a - 1) / a;
            pq.emplace(x + 2 * d, need);
            ans += need;
            to_rem += need;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

