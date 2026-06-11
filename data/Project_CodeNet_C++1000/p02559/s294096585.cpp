#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <cstdio>
using namespace atcoder;
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n, q; cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i, n){
        ll a; cin >> a;
        fw.add(i, a);
    }
    rep(i, q){
        int m; ll a, b; cin >> m >> a >> b;
        if(m==0){
            fw.add(a, b);
        }else{
            ll sum = fw.sum(a, b);
            cout << sum << ln;
        }
    }
}