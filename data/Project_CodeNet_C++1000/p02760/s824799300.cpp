#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,x,a[10],count[10],k;
    rep(i,9){
        cin>>a[i];
        count[i]=0;
    }
    cin>>n;
    rep(i,n){
        cin>>x;
        rep(j,9){
            if(a[j]==x){
                count[j]=1;
                break;
            }
        }
    }
    k=max({count[0]+count[1]+count[2],count[3]+count[4]+count[5],count[6]+count[7]+count[8],count[0]+count[3]+count[6],count[1]+count[4]+count[7],count[2]+count[5]+count[8],count[0]+count[4]+count[8],count[2]+count[4]+count[6]});
    if(k==3){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}