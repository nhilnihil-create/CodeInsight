#include<algorithm>     //sort,二分探索,など
#include<bitset>        //固定長bit集合
#include<cmath>         //pow,logなど
#include<complex>       //複素数
#include<deque>         //両端アクセスのキュー
#include<functional>    //sortのgreater
#include<iomanip>       //setprecision(浮動小数点の出力の誤差)
#include<iostream>      //入出力
#include<iterator>      //集合演算(積集合,和集合,差集合など)
#include<map>           //map(辞書)
#include<numeric>       //iota(整数列の生成),gcdとlcm(c++17)
#include<queue>         //キュー
#include<set>           //集合
#include<stack>         //スタック
#include<string>        //文字列
#include<unordered_map> //イテレータあるけど順序保持しないmap
#include<unordered_set> //イテレータあるけど順序保持しないset
#include<utility>       //pair
#include<vector>        //可変長配列

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int N;
vector<long long> A;

void solve() {
    vector<long long> plus, minus;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 0) plus.push_back(A[i]);
        else minus.push_back(A[i]);
    }
    sort(plus.begin(), plus.end(), greater<long long>());
    sort(minus.begin(), minus.end());
    if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();
    if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();

    vector<pair<long long, long long> > res;
    long long cur = minus[0];
    for (int i = 0; i + 1 < plus.size(); ++i) {
        res.push_back({ cur, plus[i] });
        cur -= plus[i];
    }
    res.push_back({ plus.back(), cur });
    cur = plus.back() - cur;

    for (int i = 1; i < minus.size(); ++i) {
        res.push_back({ cur, minus[i] });
        cur -= minus[i];
    }

    cout << cur << endl;
    for (auto p : res) cout << p.first << " " << p.second << endl;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    solve();
}