#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//　ローカルでの実行方法は g++ main.cpp -std=c++14 -I .

int main(){
    int n, q;
    cin >> n >> q;

    fenwick_tree<ll> fw(n);
    rep(i, n) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    rep(i, q) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 0) {
            fw.add(a, b);
        }
        else {
            cout << fw.sum(a, b) << endl;
        }
    }
}
