#include <bits/stdc++.h>
#define ll long long
#define fr(i,n) for(ll i=0;i<n;i++)
using namespace std;

bool prime(ll x){
if(x==1)return false;
else{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
}
return true;
}
int main() {
    ll x;cin>>x;
    while(true){
        if(prime(x)){cout<<x;break;}
            else x++;
    }

    }
