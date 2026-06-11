#pragma GCC optimize("O3") //コンパイラ最適化用

#define _GLIBCXX_DEBUG //配列に[]でアクセス時のエラー表示
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i > ll(b); i--)
// xにはvectorなどのコンテナ
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size()) // sizeをsize_tからllに直しておく

#define INF 1000000000000 // 10^12:極めて大きい値,∞
const int MOD = 1000000007;
#define MAXR 100000 // 10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define Umap unordered_map
#define Uset unordered_set
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    int field_cnt = 0;
    if (n % 2 == 1) {
        for (int l = 1, r = n - 1; l < r; l++, r--) {
            cout << l << " " << r << endl;
            field_cnt++;
            if (field_cnt == m) {
                break;
            }
        }

    } else {
        bool already_pushed = false;
        for (int l = 1, r = n - 1; l < r; l++, r--) {
            if (!already_pushed && (r - l) * 2 <= n) {
                r--;
                already_pushed = true;
            }
            cout << l << " " << r << endl;
            field_cnt++;
            if (field_cnt == m) {
                break;
            }
        }
    }
}
