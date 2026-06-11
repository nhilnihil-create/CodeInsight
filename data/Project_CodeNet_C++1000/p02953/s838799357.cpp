#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a[100005],max=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        if(max<a[i]){
            max=a[i];
        }
        if(max-1>a[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}