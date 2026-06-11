#include <bits/stdc++.h>
using namespace std;
using ll= long long;

int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    ll x;
    if(n<b-1){
        x=n;
    }
    else{
        x=b-1;
    }

    ll ans=a*x/b-a*(x/b);
    cout<<ans<<endl;
}

