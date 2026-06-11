/**
*    created: 24.07.2020 14:26:02
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
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n+1);
    rep(i,n) cin >> v[i+1];
    vector<int> ans(n+1);
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= n; j += i) {
            if (j == i) continue;
            cnt += ans[j];
        }
        cnt %= 2;
        if (v[i] != cnt) ans[i]++;
    }
    vector<int> out;
    rep(i,n) if (ans[i+1] == 1) out.push_back(i+1);
    cout << out.size() << endl;
    int t = out.size();
    rep(i,t) {
        if (i == 0) cout << out[i];
        else cout << " " << out[i];
    } 
    cout << endl;
    return 0;
}