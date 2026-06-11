#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a[21],b[21],c[21],sum=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
        sum+=b[i];
    }
    rep(i,n-1){
        cin>>c[i];
    }
    rep(i,n-1){
        if(a[i+1]-a[i]==1){
            sum+=c[a[i]-1];
        }
    }
        cout<<sum;
}