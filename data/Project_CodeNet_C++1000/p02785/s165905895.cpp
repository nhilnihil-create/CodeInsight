#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> h(n);
    ll sum=0;
    
    if(k>n) k=n;
    
    rep(i,n){
        cin>>h[i];
        sum+=h[i];
    }
    
    sort(h.begin(),h.end(),greater<ll>());
    
    rep(i,k){
        sum-=h[i];
        h[i]=0;
    }
    
    cout<<sum<<endl;
    return 0;
}