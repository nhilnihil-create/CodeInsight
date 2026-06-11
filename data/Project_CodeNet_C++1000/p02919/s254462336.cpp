#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    vector<int> p(n); rep(i, n) cin >> p[i];

    map<int, int> mp;
    rep(i, n) mp[p[i]] = i;
    sort(p.rbegin(), p.rend());
    
    multiset<int> s;
    s.insert(-1);
    s.insert(-1);
    s.insert(n);
    s.insert(n);
    
    ll ans = 0;

    rep(i, n) {
        auto itr = s.insert(mp[p[i]]);
        int mid = mp[p[i]];
        itr++;
        int r1 = *itr;
        itr++;
        int r2 = *itr;
        itr--; itr--; itr--;
        int l1 = *itr;
        itr--;
        int l2 = *itr;
        ans += (ll)(r2 - r1) * (ll)(mid - l1) * (ll)p[i];
        ans += (ll)(r1 - mid) * (ll)(l1 - l2) * (ll)p[i];
    }

    cout << ans << endl;



    return 0;
}