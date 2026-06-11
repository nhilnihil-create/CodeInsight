#ifdef _MSC_VER
#include "stdc++.h"
#endif
#ifdef __GNUC__
#include<bits/stdc++.h>
#endif
using namespace std;

using ll = long long;

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




// ***************************************

vector<ll> calc_K(ll N){
    vector<ll> vec;

    for(ll k = 1; k * k <= N; k++){
        if (N % k == 0) {
            vec.push_back(k);
            ll j = N / k;
            if (j != k) vec.push_back(j);
        }
    }

    sort(ALL(vec));

    return vec;
}


int main(){

    ll N;
    cin >> N;

    ll ans = 0;
    // 割った余りが１
    const auto& vec = calc_K(N - 1);
    ans += vec.size() - 1;

    // 割り切れる
    const auto& vec2 = calc_K(N);

    for(auto& K: vec2){
        if (K == 1) continue;
        ll NN = N;
        while(NN % K == 0){
            NN = NN / K;
        }
        if ((NN-1) % K == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}
