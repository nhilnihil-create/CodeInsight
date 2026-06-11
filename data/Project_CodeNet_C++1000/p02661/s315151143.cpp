#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v) cerr << #v << ":"; rep(i, v.size()) cerr << " " << v[i]; cerr << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    sort(all(A));
    sort(all(B));
    int mini, maxi;
    if (n % 2 == 0) {
        mini = A[n / 2 - 1] + A[n / 2];
        maxi = B[n / 2 - 1] + B[n / 2];
    } else {
        mini = A[(n - 1) / 2];
        maxi = B[(n - 1) / 2];
    }
    cout << maxi - mini + 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
