#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll N; cin>>N;
    vector<ll> H(N);
    for(ll i=0;i<N;i++) cin>>H[i];
    ll n=0;
    for(ll i=0;i<N;i++){
        n=max(n,H[i]);
        if(n-H[i]>=2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}