#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll a,b,ans;
    cin>>a>>b;
    if(a+b==3){
        ans=3;
    }else if(a+b==4){
        ans=2;
    }else{
        ans=1;
    }
    cout<<ans;
}