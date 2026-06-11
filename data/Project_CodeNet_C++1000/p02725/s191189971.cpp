#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k,a[200005],max=0;
    cin >>k>>n;
    rep(i,n){
        cin>>a[i];
        if(i>0){
            if(max<a[i]-a[i-1]){
                max=a[i]-a[i-1];
            }
        }
    }
    if(max<k+a[0]-a[n-1]){
        max=k+a[0]-a[n-1];
    }
    cout << k-max;
}