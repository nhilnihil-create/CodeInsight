#ifdef _MSC_VER
#include "stdc++.h"
#endif
#ifdef __GNUC__
#include<bits/stdc++.h>
#endif
using namespace std;

using ll = long long;

//vector
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

//constant
const double EPS = 1e-10;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, s, e) for (ll i = s; i < e; i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(), (x).rend()

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

// vector
//template<typename T> vector<vector<T>> vv(ll H, ll W, T v) { return vector<vector<T>> vec(H, vector<T>(W, v)); }

// view vector
template<typename T> void view(T e) { cout << e << endl; }
template<typename T> void view(const vector<T>& v) { for (const auto& e : v) { cout << e << " "; } cout << endl; }
template<typename T> void view(const vector<vector<T> >& vv) { for (const auto& v : vv) { view(v); } }

// DP
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


vll calc(ll N) {
    vll ret;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ret.push_back(i);
            ll j = N / i;
            if (j != i) ret.push_back(j);
        }
    }
    sort(ALL(ret));
    
    return ret;
}


int main() {

    ll N;
    cin >> N;

    const auto vec1 = calc(N);
    const auto vec2 = calc(N - 1);

    ll ans = vec2.size() - 1;

    for (auto x : vec1) {
        if (x == 1) continue;
        auto NN = N;
        while (NN % x == 0) NN /= x;
        if ((NN - 1) % x == 0) ans++;
    }

    cout << ans << endl;

#ifdef _MSC_VER
    system("PAUSE");
#endif

    return 0;
}