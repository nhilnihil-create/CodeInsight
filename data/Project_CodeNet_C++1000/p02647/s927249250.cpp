#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < (ll)n; i++)

int main() {
    ll N;
    ll K;
    cin>>N>>K;
    vector<ll> A(N,-1);
    rep(i,N){
        cin>>A[i];
    }
    if(K >= 50){
        K = 50;
    }
    while(K--){
        vector<ll> B(N,0);
        rep(i,N){
            ll l = max((ll) 0,i-A[i]);
            B[l]++;
            ll r = min(N-1,i+A[i]);
            if(r+1<N){
                B[r+1]--;
            }
        }
        rep(i,N-1){
            B[i+1]+=B[i];
        }
        A = B;
    }
    for(auto x: A){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}