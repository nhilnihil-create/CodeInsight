#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

ll mod = 1'000'000'000 + 7;
int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    vector<ll> CT(2000+10,0);
    rep(i,N){
        int x; cin>>x;
        A[i]=x;
        CT[x]++;
    }

    // ブロックごと
    ll ans=0;
    ll bbsum=0;
    for(ll i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i]>A[j]){
                bbsum++;
            }
        }
    }
    ll kk = (K*(K-1))/2%mod;
    ans += (bbsum * kk );
    ans %= mod;
    cerr << ans << endl;
    // ans /= 2;

    cerr << ans << endl;
    // 各ブロック
    ll bsum=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(A[i]>A[j]){
                bsum++;
            }
        }
        bsum %= mod;
    }
    bsum = (bsum * K)%mod;
    ans += bsum;
    ans %= mod;
    cout << ans << endl;
}
