#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;


int main(){
    ll n,i=2,ans;
    cin>>n;
    while(1){
        if(n<i){
          	i/=2;
            break;
        }
        i*=2;
    }
    ans=i*2-1;
    cout<<ans;
}