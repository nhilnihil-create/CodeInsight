#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    while(cin>>n){
        ll arr[n+1];
        ll occ[n+1];
        memset(occ,0,sizeof occ);
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
            occ[arr[i]]++;
        }
        long long ans=0;
        for(ll i=1;i<=n;i++){
            ll l=occ[i];
            ans+=((l*(l-1))/2);
        }
        for(ll i=1;i<=n;i++){
            ll val=arr[i];
            ll x=occ[val];
            ll temp=ans;
            temp-=(x*(x-1))/2;
            x--;
            temp+=(x*(x-1))/2;
            cout << temp << endl;
        }
    }
    return 0;
}
