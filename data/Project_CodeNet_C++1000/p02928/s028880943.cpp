#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll mod = 1e9+7;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    ll t = 0;
    rep(i, 0, N-1){
        rep(j, i+1, N){
            if(A[i] > A[j]){
                t++;
                t %= mod;
            }
        }
    }
    ll ans = t * K;
    ans %= mod;
    ll cnt = 0;
    rep(i, 0, N){
        rep(j, 0, N){
            if(A[i] < A[j]){
                cnt++;
                cnt %= mod;
            }
        }
    }
    ans += ((K * (K-1)/ 2) % mod) * cnt;
    ans %= mod;
    cout << ans << endl;
    return 0;
}