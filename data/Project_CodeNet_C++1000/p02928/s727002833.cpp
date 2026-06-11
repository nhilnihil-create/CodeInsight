#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++){
        for (ll j = i; j < N; j++){
            if (A[i] > A[j]){
                ans = (ans + (((K + 1) * K) / 2) % 1000000007) % 1000000007;
            }
            else if (A[i] < A[j]){
                ans = (ans + (((K - 1) * K) / 2) % 1000000007) % 1000000007;
            }
        }
    }
    cout << ans << endl;
}
