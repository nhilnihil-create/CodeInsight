#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

struct SuperSet{
    int k;
    ll sum = 0;
    multiset<int> s;
    SuperSet(int k) : k(k) {}
    void insert(int x) {
        if ((int)s.size() < k) {
            sum += x;
            s.insert(x);
            return;
        }
        if (*s.begin() < x) {
            sum -= *s.begin();
            s.erase(s.begin());
            s.insert(x);
            sum += x;
        }
        return;
    }
    ll get() {
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (auto &l : p) cin >> l;
    for (auto &l : q) cin >> l;
    for (auto &l : r) cin >> l;
    sort(all(p));
    sort(all(q));
    sort(all(r));
    reverse(all(p));
    reverse(all(q));
    reverse(all(r));
    SuperSet s(y);
    for (auto &l : q) s.insert(l);
    ll sump = 0, ans = 0;
    int j = c - 1;
    vector<ll> pr(c + 1);
    for (int i = 0; i < c; i++) pr[i + 1] = pr[i] + r[i];
    for (int i = 0; i <= x; i++) {
        if (i > 0) sump += p[i - 1];
        if (x - i > c) continue;
        while (j >= x - i) {
            s.insert(r[j]);
            j--;
        }
        ans = max(ans, sump + s.get() + pr[x - i]);
    }
    cout << ans;
    return 0;
}
