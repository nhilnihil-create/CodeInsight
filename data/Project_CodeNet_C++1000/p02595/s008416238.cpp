#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll N,D; cin>>N>>D;
    ll ans=0;
    for (ll i = 0; i < N; i++){
        ll x,y; cin>>x>>y;
        ll dis=x*x+y*y;
        if(D*D>=dis){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}