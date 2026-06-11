#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,d;
    cin>>n>>d;
    ll ans=0;
    while(n--){
        ll a,b;
        cin>>a>>b;
        ll D=a*a+b*b;
        if((ll)(d*d)>=D)
         ans++;
    }
    cout<<ans<<endl;
   
}
