#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
constexpr long long MOD2 = 998244353;
constexpr double EPS = 1e-10;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;



int n;

ull a[200019];

ull umin (ull a, ull b) {
    return (a < b) ? a : b;
}
ull umax (ull a, ull b) {
    return (a > b) ? a : b;
}

int main() {

    cin >> n;
    rep(i, n) cin >> a[i];


    ll i, j;
    ull res = 0;

    ull allxor = 0;
    for (i = 0; i < n; i++) {
        allxor ^= a[i];
    }
    for (i = 0; i < n; i++) {
        a[i] &= ~allxor; //interstingなbitだけ立たせる(最後に考慮)
    }

    //F2における掃き出し法
    ull rank = 0;
    for (i = 59; i >= 0; i--) {
        //i-bitが0でない最初の行j>=rankを探す　なかったら次のiへ
        for (j = rank; j < n; j++) {
            if (a[j] & (1 << i)) break;
        }
        if (j == n) continue;

        if (j > rank) a[rank] ^= a[j];  //a[rank] = a[rank] + a[j] in F2
        for (j = rank + 1; j < n; j++) {
            a[j] = min(a[j], a[j] ^ a[rank]);
        }

        rank++;
    }

    ull x = 0;
    for (i = 0; i < n; i++) { //高いbitが立ってる方からgreedyに
        x = max(x, x ^ a[i]);
    }

    res = (x * 2) + allxor;

    cout << res << endl;

}


