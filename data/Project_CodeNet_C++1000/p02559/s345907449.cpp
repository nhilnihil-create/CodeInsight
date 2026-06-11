#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;

int main(){
    ll n,q;
    cin >> n >> q;
    fenwick_tree<ll> ft(n);
    rep(i,n){
        cin >> t1;
        ft.add(i,t1);
    }
    rep(i,q){
        cin >> t1 >> t2 >> t3;
        if(t1 == 0){
            ft.add(t2,t3);
        }else{
            cout << ft.sum(t2,t3) << endl;;
        }
    }
}