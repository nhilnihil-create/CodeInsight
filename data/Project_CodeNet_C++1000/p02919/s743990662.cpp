#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> id(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        id[p[i]] = i;
    }
    multiset<int> se;
    se.insert(-1);
    se.insert(-1);
    se.insert(n);
    se.insert(n);
    ll ans = 0;
    for(int num = n; num >= 1; num--) {
        int i = id[num];
        auto it = se.lower_bound(i);
        int y = *it;
        int z = *(++it);
        it--;
        int x = *(--it);
        int w = *(--it);
        ans += (ll)num * ((ll)(x - w) * (y - i) + (ll)(i - x) * (z - y));
        se.insert(i);
    }
    print(ans);
}