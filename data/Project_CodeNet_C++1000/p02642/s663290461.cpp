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
using vii = vector<vi>;
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




// ***************************************


int main(){

    int N;
    cin >> N;

    vll A(N);
    ll mx = 0;
    ll cnt1 = 0;
    REP(i, N){
        cin >> A[i];
        chmax(mx, A[i]);
        if (A[i] == 1) cnt1++;
    }

    if(cnt1 == 1){
        cout << 1 << endl;
        return 0;
    } else if (cnt1 > 1){
        cout << 0 << endl;
        return 0;
    }

    vll B(mx + 1, 0);
    for(ll a: A){
        ll i = a;
        while(i <= mx){
            B[i]++;
            i += a;
        }
    }

    ll ans = 0;
    for(ll a: A){
        if(B[a] == 1) ans ++;
    }
    cout << ans << endl;
    

    return 0;
}
