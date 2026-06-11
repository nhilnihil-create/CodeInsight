#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    vector<ll> guess(n+1); guess[0] = 0;
    for(int i=1; i<n+1; i++){
        guess[i] = A[i-1] - guess[i-1];
    }
    vector<ll> res(n);
    res[0] = guess[n];
    for(int i=1; i<n; i++){
        res[i] = (A[i-1] -  res[i-1]/2)*2;
    }
    rep(i, n) cout << res[i] << " ";
    cout << ln;
}
