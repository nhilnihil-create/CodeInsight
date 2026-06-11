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

int N, K, C;

vll calc(string S){
    int last = -C - 1;

    vll ret(N + 1, 0);
    ll cur = 0;
    REP(i, N){
        if (S[i] == 'o' && i - last > C) {
            last = i;
            cur++;
        }
        ret[i + 1] = cur;
    }

    return ret;
}

int main(){

    cin >> N >> K >> C;
    string S;
    cin >> S;
    
    const auto left = calc(S);
    string T = S;
    reverse(ALL(T));
    const auto right = calc(T);

    bool flag = false;
    REP(i, N){
        if (S[i] == 'x') continue;
        if (left[i] + right[N - i - 1] < K) {
            cout << i + 1 << endl;
            flag = true;
        }
    }

    if(!flag) cout << endl;

    return 0;
}
