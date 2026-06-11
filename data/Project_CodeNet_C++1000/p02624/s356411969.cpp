#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll fun(ll a,ll N){
     
     ll tmp=N/a;

    return  a*(tmp+1)*tmp/2;
}


int main(){

    ll N;
    cin>>N;

    ll ans=0;

    for(ll i=1;i<=N;i++){
        ans+=fun(i,N);
    }

    cout<<ans<<endl;

}