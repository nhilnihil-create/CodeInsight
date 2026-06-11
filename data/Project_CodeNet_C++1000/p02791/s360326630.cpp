#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a,min=200001,cnt=0;
    cin>>n;
    rep(i,n){
        cin>>a;
        if(min>a){
            min=a;
        }else{
            cnt++;
        }
    }
    cout<<n-cnt;
}