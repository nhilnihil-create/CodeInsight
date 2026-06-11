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

int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll> height(N);
    vector<ll> good(N,1);
    rep(i,N){
        cin>>height[i];
    }
    int a,b;
    rep(i,M){
       cin>>a>>b; 
       if(height[a-1]<=height[b-1]){
           good[a-1]=0;
       }
       if(height[b-1]<=height[a-1]){
           good[b-1]=0;
       }   
       
    }
    int ans=0;
    rep(i,N){
        ans+=good[i];
    }
    cout<<ans<<endl;
}

