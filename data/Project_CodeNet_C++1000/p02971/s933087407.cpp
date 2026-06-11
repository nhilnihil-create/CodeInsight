#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,x,k,max=0,ma=0;
    cin>>n;
    rep(i,n){
        cin>>x;
        if(max<x){
            ma=max;
            max=x;
            k=i;
        }else if(ma<x){
            ma=x;
        }
    }
    rep(i,n){
        if(i==k) cout<<ma<<endl;
        else cout<<max<<endl;
    }
}