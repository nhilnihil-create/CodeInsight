#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
#define MAX_X 100000001
//#define MAX_X 100001

class SegTree {
public:
    const int MAX_N = 1 << 17;
    int n;
    vector<ll> dat;
    const ll INITIAL_DAT = 0L;

    SegTree(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<ll>(2 * n);
        for (int i = 0; i < 2 * n - 1; ++i) dat[i] = INITIAL_DAT;
    }

    //どんなSegTreeを構築するか(デフォルトはRMQ)
    ll calc(ll vl, ll vr) {
        return min(vl, vr);
    }

    //k番目の値(0-indexed)をaに変更
    void update(int k, int a) {
        k += n - 1;
        dat[k] = a;
        //登りながら更新
        while (k > 0) {
            k = (k - 1) / 2;
//            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
            dat[k] = calc(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    //[a,b)の最小値を求める
    //kは接点の番号,l,rはその接点が[l,r)に対応づいていることを表す。
    //したがって、外からはquery(a,b,0,0,n)として呼ぶ。
    ll query(int a, int b, int k, int l, int r) {
        //[a,b)と[l,r)が交差しなければINITIAL_DAT
        if (r <= a || b <= l) return INITIAL_DAT;

        //[a,b)が[l,r)が交差しなければ、INT_MAX
        if (a <= l && r <= b) return dat[k];
        else {
            //そうでなければ、2つの子に対する処理,デフォルトは最小値
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return calc(vl, vr);
        }
    }

    //[a,b)の最小値を求める
    ll find(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};

class Solve {
public:
    int N = 0;
    vector<Int> X, Y;


    void solve() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Int x, y;
            cin >> x >> y;
            if (x || y) {
                X.push_back(x);
                Y.push_back(y);
                N++;
            }
        }


        double ans = 0.0;

        vector<int> idxes(N);
        for (int i = 0; i < N; ++i) {
            idxes[i] = i;
        }

        sort(all(idxes), [&](int a, int b) {
            double A = atan2(X[a], Y[a]);
            double B = atan2(X[b], Y[b]);

            return A < B;
        });

        for (int l = 0; l < N; ++l) {
            for (int r = 0; r < N; ++r) {
                Int x1 = 0;
                Int y1 = 0;
                Int x2 = 0;
                Int y2 = 0;

                for (int i = 0; i < N; ++i) {
                    if (i >= l && i <= r) {
                        x1 += X[idxes[i]];
                        y1 += Y[idxes[i]];
                    } else {
                        x2 += X[idxes[i]];
                        y2 += Y[idxes[i]];
                    }
                }

                Int tmp = max(x1 * x1 + y1 * y1, x2 * x2 + y2 * y2);
                chmax(ans, sqrt(tmp));
            }
        }


        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
