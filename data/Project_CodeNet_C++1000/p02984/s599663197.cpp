/**
*    created: 28.07.2020 20:30:00
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[8] = {0, 1, 0, -1, 1, 1,-1, -1};
const int dy2[8] = {1, 0,-1, 0, 1, -1, 1, -1};
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    int e = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
        if (i % 2 == 1) e += a[i];
    }
    vector<int> b(n);
    rep(i,n) {
        if (i == 0) b[i] = sum - 2 * e;
        else b[i] = 2 * a[i-1] - b[i-1];
    }
    rep(i,n) {
        if (i == 0) cout << b[i];
        else cout << " " << b[i];
    }
    cout << endl;
    return 0;
}