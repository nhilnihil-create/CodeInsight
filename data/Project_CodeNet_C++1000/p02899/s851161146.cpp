#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,x;
    cin>>n;
    int a[n];
    rep(i,n){
        cin>>x;
        a[x-1]=i+1;
    }
    rep(i,n){
        cout<<a[i];
        if(i<n-1){
            cout<<" ";
        }
    }
}