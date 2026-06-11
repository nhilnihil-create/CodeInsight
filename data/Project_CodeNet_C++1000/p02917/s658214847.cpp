#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;
 
 
int main(){
    ll n,a[205],ans=0;
    cin>>n;
    rep(i,n-1){
        cin>>a[i];
        if(i==0){
            ans+=a[i];
        }else{
            if(a[i]<a[i-1]) ans+=a[i];
            else ans+=a[i-1];
        }
    }
  ans+=a[n-2];
    cout<<ans;
}