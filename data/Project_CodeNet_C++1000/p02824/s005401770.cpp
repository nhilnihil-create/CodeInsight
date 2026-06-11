#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v, p;
    cin >> n >> m >> v >> p;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int ok = p-1;
    int ng = n;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        ll total = 0;
        rep(i, n) {
            if (i < p-1 || i >= mid+1) {
                total += m;
            } else {
                if (a[i] > a[mid] + m) {
                    total = -1;
                    break;
                }
                total += max(a[mid] + m - a[i], 0);
            }
        }
        if (total >= (ll)m*v) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok + 1 << endl;
}