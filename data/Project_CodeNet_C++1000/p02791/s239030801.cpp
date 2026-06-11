#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll N; cin>>N;
    vector<ll> p(N);
    for (ll i = 0; i < N; i++){
        cin>>p[i];
    }
    ll m=p[0],ans=1;
    for (ll i = 1; i < N; i++){
        if(m>p[i]){
            m=p[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}