/**
*	created: 10.08.2020 00:10:36
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
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

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int x = 0, y = 0;
    if (s[0] == 'L') y++;
    if (s[n-1] == 'R') y++;
    rep(i,n-1) if (s[i] == 'R' && s[i+1] == 'L') x++;
    int ans = n - 2 * x - y;
    if (k > x + y) ans = n-1;
    else if (k > x) ans += x + k;
    else ans += k*2;
    cout << ans << endl;
    return 0;
}
