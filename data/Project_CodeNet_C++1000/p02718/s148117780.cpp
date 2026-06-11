#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll a,b,c[1001],k=0,sum=0;
    cin >> a>>b;
    rep(i,a){
        cin >> c[i];
        sum+=c[i];
    }
    rep(i,a){
        if(c[i]*4*b>=sum){
            k++;
        }
    }
    if(k>=b){
        cout <<"Yes";
    }else{
        cout <<"No";
    }
}