
#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){

    int N; cin >> N;
    ll K; cin >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll ng = 0;
    ll ok = 1e9;
    
    while(abs(ok-ng)>1){
        ll mid = (ok+ng) / 2;
        auto f = [&](ll mid){
            ll count = 0;
            rep(i,N){
                count += (A[i]+(mid-1))/mid-1;
            }
            return count <= K; 
        };
        if(f(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

}