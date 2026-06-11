#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N; cin>>N;
    if(N%2==1){
        cout<<0<<endl;
        return 0;
    }
    N/=2;
    ll ans=0;
    ll x=5;
    while(N/x>0){
        ans+=N/x;
        x*=5;
    }
    cout<<ans<<endl;
}