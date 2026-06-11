#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    int n; ll k; cin >> n >> k;
    vector<ll>A(n), F(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> F[i];
  
    sort(all(A), greater<ll>());
    sort(all(F));
    ll ng = -1, ok = 1e12 + 1;
    while(ok - ng > 1){
        ll mid = (ok+ng)/2, sum = 0;
        rep(i, n){
            ll num = A[i]*F[i]-mid;
            if(num>0){
                sum += num / F[i];
                if(num%F[i]>0) sum++;
            }
        }
        if(sum <= k)ok = mid;   
        else ng = mid;    
    }
    cout << ok << ln;
}