#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    
    ll n,m;
    cin>>n>>m;
    
    ll ans = n*(n-1)/2;
    ll ans1 = m*(m-1)/2;
    cout<<ans+ans1;
    
    
}