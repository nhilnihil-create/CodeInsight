#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n;
vector <pii> v;

multiset <int> s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        v.push_back(MP(x, i));
    }
    s.insert(0), s.insert(0);
    s.insert(n + 1), s.insert(n + 1);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll ans = 0;
    for(auto i : v) {
        int num = i.fi, p = i.se;
        auto it = s.lower_bound(p);
        int R1 = *it++;
        int R2 = *it--;
        --it;
        int L1 = *it--;
        int L2 = *it;
        if(L1) ans += 1ll * num * (L1 - L2) * (R1 - p);
        if(R1 <= n) ans += 1ll * num * (p - L1) * (R2 - R1);
        s.insert(p);
    }
    cout << ans;
    return 0;
}