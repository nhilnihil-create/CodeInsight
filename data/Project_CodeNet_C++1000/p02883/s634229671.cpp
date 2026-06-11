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
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {    
    int n; ll k; cin >> n >> k;
    vector<ll> A(n), F(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> F[i];

    sort(all(A));
    sort(all(F), greater<ll>());

    ll ng = 0, ok = 1e12+1;
    while(ng < ok){
        ll mid = (ng + ok) / 2, sum = 0;
        rep(i, n){
            sum += max(0LL,(A[i] * F[i] - mid + F[i] - 1) / F[i]);
        }
        if(sum <= k) ok = mid;
        else ng = mid + 1;
    }
    cout << ok << ln;
} 
