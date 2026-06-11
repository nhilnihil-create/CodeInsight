#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,x[101],sum=0,min=mod;
    cin>>n;
    rep(i,n){
        cin>>x[i];
    }
    rep(i,100){
        sum=0;
        rep(j,n){
            sum+=(x[j]-i)*(x[j]-i);
        }
        if(min>sum){min=sum;}
    }
    cout<<min;
}