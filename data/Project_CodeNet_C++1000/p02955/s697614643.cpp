#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

bool check(int r, vint &a, int upper) {
    vint v;
    int n = a.size();
    rep(i,n) v.push_back(a[i] % r);
    sort(all(v));
    vll sum_l(n + 1, 0), sum_r(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum_l[i] += sum_l[i-1] + v[i-1];
        sum_r[i] += sum_r[i-1] + (r - v[n-i]);
    }
    bool res = false;
    for (int i = 1; i <= n; i++) {
        if (max(sum_l[i], sum_r[n-i]) <= upper) res = true;

    }
    return res;
}

int main() {
    int n, k; cin >> n >> k;
    vint a(n);
    rep(i,n) cin >> a[i];
    int sum = 0;
    rep(i,n) sum += a[i];
    int ans = 0;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i != 0) continue;
        if (check(i, a, k)) chmax(ans, i);
        if (check(sum / i, a, k)) chmax(ans, sum / i);
    }
    cout << ans << endl;
}