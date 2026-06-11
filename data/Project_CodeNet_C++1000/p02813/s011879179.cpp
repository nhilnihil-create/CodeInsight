#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k[8]={1,2,3,4,5,6,7,8},p[8],q[8],a,b,check=0,cnt=1;
    cin>>n;
    rep(i,n){
        cin>>p[i];
    }
    rep(i,n){
        cin>>q[i];
    }
    do {
        check=0;
        rep(i,n){
            if(k[i]!=p[i]) check=1;
        }
        if(check==0){a=cnt;}
        check=0;
        rep(i,n){
            if(k[i]!=q[i]) check=1;
        }
        if(check==0){b=cnt;}
        cnt++;
    } while(next_permutation(k,k+n));
    cout<<abs(a-b);
}