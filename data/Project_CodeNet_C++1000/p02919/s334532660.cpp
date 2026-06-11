#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    multiset<int> S;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        v[i] = pii(p, i);
    }
    sort(rall(v));

    S.insert(-1);
    S.insert(-1);
    S.insert(n);
    S.insert(n);

    ll res = 0;
    for (auto x : v) {
        ll val = x.first;
        int id = x.second;

        auto itr = S.upper_bound(id);
        int r1 = *itr;
        itr++;
        int r2 = *itr;
        itr--; itr--;
        int l1 = *itr;
        itr--;
        int l2 = *itr;
        res += val * (r2 - r1) * (id - l1);
        res += val * (r1 - id) * (l1 - l2);
        S.insert(id);
    }
    cout << res << endl;
}