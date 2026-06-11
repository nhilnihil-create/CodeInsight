#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k=0,ans;
    cin>>n;
    rep(i,sqrt(n-1.0)){
        if(n%(i+1)==0){
            k=i+1;
        }
    }
    ans=n/k+k-2;
    cout<<ans;
}