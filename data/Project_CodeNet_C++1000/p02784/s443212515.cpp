#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,h,x,sum=0;
    cin>>h>>n;
    rep(i,n){
        cin>>x;
        sum+=x;
    }
    if(sum<h){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}