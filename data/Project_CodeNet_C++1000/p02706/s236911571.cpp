#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,m,a[10001],sum=0;
    cin >> n >> m ;
    rep(i,m){
        cin >> a[i];
        sum+=a[i];
    }
    if(n<sum){
        sum=-1;
    }else{
        sum=n-sum;
    }
    cout << sum;
}