#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    ll arr[n],s=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i+=2) 
        s+=(arr[i]&1); 
    cout<<s<<"\n";
}