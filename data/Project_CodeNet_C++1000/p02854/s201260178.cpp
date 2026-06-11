#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll sum(n+1, 0);
    rep(i, n) sum[i+1] = sum[i] + a[i];
    int idx = lower_bound(sum.begin(), sum.end(), sum[n]/2.0) - sum.begin();
    ll l1 = sum[idx];
    ll l2 = sum[n] - sum[idx];
    ll ans = abs(l1 - l2);
    ll l3 = sum[idx-1];
    ll l4 = sum[n] - sum[idx-1];
    chmin(ans, abs(l3 - l4));
    cout << ans << endl;
}