#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll A,B; cin>>A>>B;
    ll ans=0,out=1;
    while(out<B){
        out--;
        out+=A;
        ans++;
    }
    cout<<ans<<endl;
}