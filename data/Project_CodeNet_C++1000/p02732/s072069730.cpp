#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
    int n; cin >> n;
    vector<ll> A(n), C(200010);
    rep(i, n){
        cin >> A[i];
        C[A[i]]++;
    }
    ll sum = 0;
    rep(i, 200001){
        ll tmp = C[i];
        sum += tmp * (tmp-1) / 2;
    }
    //クエリ
    rep(i, n){
        ll tmp = C[A[i]];
        ll res = sum - tmp * (tmp-1) / 2 + (tmp-1)*(tmp-2) / 2;
        cout << res << ln;
    }
}