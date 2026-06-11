#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a[200005],count[200005],ans=1;
    rep(i,200005){
        count[i]=0;
    }
    cin>>n;
    rep(i,n){
        cin>>a[i];
        count[a[i]]++;
    }
    rep(i,200005){
        ans+=count[i]*(count[i]-1)/2;
    }
    rep(i,n){
        cout<<ans-count[a[i]]<<endl;
    }
}