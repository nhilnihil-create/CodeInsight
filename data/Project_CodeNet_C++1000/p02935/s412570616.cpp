#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,a[200005];
    double p;
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    p=a[0];
    rep(i,n-1){
        p=(p+a[i+1])/2.0;
    }
    cout<<p;
}