#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define rep(i, m, n) for (int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for (int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef vector<vector<vector<ll>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// vector<long long> v(n), c(n);
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
bool is_prime(int x){
    if(x<=1) return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
int main() {
    int x;
    cin >> x;
    int res = 0;
    rep(i,x,x+100000) if (is_prime(i)) cout << i << '\n',exit(0);

    return 0;
}
