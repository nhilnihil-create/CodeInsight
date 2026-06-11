#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
 
int main(){
    int mod=2019;
    ll L,R;cin >> L>>R;
    ll Min=2019;
    ll judge = R-L+1;
    if(judge>=2020) cout << 0<<endl;
    else{
        for(ll i=L;i<R;i++){
        for(ll j=i+1;j<=R;j++){
            ll t = i%mod*j%mod;
            Min=min(Min,t);
        }
    }
    cout<< Min<<endl;
    }    
}