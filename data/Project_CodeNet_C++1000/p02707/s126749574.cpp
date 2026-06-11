#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,x,a[200001];
    cin >> n ;
    rep(i,n){
        a[i]=0;
    }
    rep(i,n-1){
        cin >> x;
        a[x-1]++;
    }
    rep(i,n){
        cout << a[i] << endl;
    }
}