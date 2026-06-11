#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1;i<=n;i++)
        v[i]=0;
    for(ll i=1;i<=n;i++){
        ll mult=i;
        while(mult<=n){
            v[mult]++;
            mult+=i;
        }
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
        sum=sum+(i*v[i]);
    cout<<sum;
    return 0;
}
