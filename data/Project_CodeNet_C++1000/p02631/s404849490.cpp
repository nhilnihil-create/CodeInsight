#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a[200005],k,sum=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        sum=sum ^ a[i];
    }
    rep(i,n){
        k=sum^a[i];
        cout<<k;
        if(i<n-1){
            cout<<" ";
        }
    }
}