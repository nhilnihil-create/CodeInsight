#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,k,q,x,a[100005];
    cin>>n>>k>>q;
    rep(i,n){
        a[i]=k-q;
    }
    rep(i,q){
        cin>>x;
        a[x-1]++;
    }
    rep(i,n){
        if(a[i]>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}