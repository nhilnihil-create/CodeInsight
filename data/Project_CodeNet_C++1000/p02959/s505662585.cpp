#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    rep(i,n+1){
        cin>>v[i];
    }
    vector<ll>y(n);
    rep(i,n){
        cin>>y[i];
    }
    ll tmp;
    ll sum=0;
    rep(i,n){
        if(v[i]<=y[i]){
           tmp=v[i] ;
           v[i]=0;
           y[i]-=tmp;
           sum+=tmp;
        }else{
        tmp=y[i] ;
           v[i]-=tmp;
           y[i]=0;
           sum+=tmp;
        }
        if(y[i]==0)continue;
        tmp=min(y[i],v[i+1]);
        y[i]-=tmp;
        v[i+1]-=tmp;
        sum+=tmp;
    }
    
   cout<<sum<<endl;
}
