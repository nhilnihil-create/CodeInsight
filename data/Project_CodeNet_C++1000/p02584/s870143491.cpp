#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll x,k,d;
    cin>>x>>k>>d;
    if(k<=abs(x)/d) cout<<abs(x)-k*d<<endl;
    else{
        ll cnt=abs(x)/d;
        if((k-cnt)%2) cout<<abs(abs(x)%d-d)<<endl;
        else cout<<abs(x)%d<<endl;
    }
    return 0;
}