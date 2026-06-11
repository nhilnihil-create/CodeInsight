#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    if(k<=x/d) cout<<x-k*d<<endl;
    else{
        if((k-x/d)%2) cout<<d-x%d<<endl;
        else cout<<x%d<<endl;
    }
    return 0;
}