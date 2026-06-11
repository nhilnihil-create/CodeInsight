#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
ll l[200];
int solve(){
    ll x,k,d,m;
    cin>>x>>k>>d;
    if (x==0){
        if (k%2==0)return cout<<0<<endl,0;
        else return cout<<d<<endl,0;
    }
    if (x<0)x=-x;
    ll n=x/d;
    if(x<d){
        if (k%2==0)return cout<<x<<endl,0;
        else return cout<<d-x<<endl,0;
    }
    if (n<k){
        if (n>0) m=x%d;
        if((k-n)%2==0)cout<<m<<endl;
        else cout<<d-m<<endl;
        return 0;
    } else{
        m=x-k*d;
        cout<<m<<endl;
        return 0;
    }
}
int main(){
    int _=1;
    while(_--){
        solve();
    }
}