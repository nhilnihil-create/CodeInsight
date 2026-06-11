#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a,b,k,p,ans;
    cin >>n>>a>>b;
    k=n/(a+b);
    p=n%(a+b);
    if(p<a){
        ans=p;
    }else{
        ans=a;
    }
  ans+=k*a;
    cout <<ans;
}