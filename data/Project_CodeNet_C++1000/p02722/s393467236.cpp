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

vector<ll> calc(ll N){
    vector<ll> ret;
    for (ll i = 1; i * i <= N; i++){
        if (N % i == 0){
            ret.push_back(i); 
            ll j = N / i;
            if (i != j) ret.push_back(j);
        }
    }
    sort(ALL(ret));

    return ret;

}


int main(){

    ll N;
    cin >> N;

    const vector<ll> &vec1 = calc(N);
    const vector<ll> &vec2 = calc(N-1);

    ll ans = vec2.size() - 1;

    for(auto& v: vec1) {
        if (v == 1) continue;

        ll NN = N;
        while(NN % v == 0) NN /= v;
        if ((NN - 1) % v == 0) ans++;
    }


    cout << ans << endl;

    return 0;
}
