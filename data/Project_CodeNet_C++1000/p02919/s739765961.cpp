#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

int n, c[maxn];
set<int> s;

int main(void) {
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cin >> n;
    s.insert(0);    s.insert(n + 1);
    for(int i = 1; i <= n; ++i) {
        int p;  cin >> p;
        c[p] = i;
    }
    ll ans = 0;
    for(int i = n; i >= 1; --i) {
        auto it = s.lower_bound(c[i]);
        if(prev(it) != s.begin()) {
            ans += 1LL * i * (*prev(it) - *prev(prev(it))) * (*it - c[i]);
        }
        if(next(it) != s.end()) {
            ans += 1LL * i * (c[i] - *prev(it)) * (*next(it) - *it);
        }
        s.insert(c[i]);
    }
    cout << ans;
    return 0;
}