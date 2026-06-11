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
#include <cassert>


using namespace std;
#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<n;++i)
#define FOR(i, a, b) for(int i=a;i<b;++i)
#define RREP(i, n) for(int i=n-1;i>=0;--i)
#define RFOR(i, a, b) for(int i=b-1;i>=a;--i)

#define all(x) begin(x),end(x)
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
    os << p.first << ":" << p.second;
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T1, class T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
    os << "[";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it != mp.begin()) {
            os << ", ";
        }
        os << *it;
    }
    return os << "]";
}

// edit
struct Solve {

    int N;
    vector<ll> A;
    vector<vector<ll>> dp;
    vector<int> idx;

    ll rec(int L, int R) {
        if (L == 0 && R == 0) {
            return 0;
        }
        if (dp[L][R] != -1) {
            return dp[L][R];
        }

        ll &ret = dp[L][R];

        ll val1 = -1, val2 = -1;
        if (L > 0) {
            val1 = rec(L - 1, R) + abs(idx[L + R - 1] - (L - 1)) * A[idx[L + R - 1]];
        }
        if (R > 0) {
            val2 = rec(L, R - 1) + abs(idx[L + R - 1] - (N - R)) * A[idx[L + R - 1]];
        }

        ret = max(val1, val2);

        return ret;
    }


    void solve() {
        cin >> N;
        A.resize(N);
        idx.resize(N);
        iota(all(idx), 0);
        dp.resize(N + 1, vector<ll>(N + 1, -1));

        REP(i, N) cin >> A[i];
        sort(all(idx), [&](int l, int r) {
            return A[l] > A[r];
        });

        ll ans = -1;

//        cerr << rec(0, 1) << endl;

        for (int i = 0; i < N; ++i) {
            ll tmp = rec(i, N - i);
//            cerr << tmp << endl;
            chmax(ans, tmp);
        }

//        for (int l = 0; l <= N; ++l) {
//            for (int r = 0; r + l <= N; ++r) {
//                cout << make_pair(l, r) << " " << rec(l, r) << endl;
//            }
//            cout << endl;
//        }


        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    Solve().solve();


    return 0;
}
