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
    ll N,K;
    cin>>N>>K;
    vector<ll>sunuke(N);
    ll a,b;
    rep(i,K){
        cin>>a;
        rep(j,a){
           cin>>b;
           sunuke[b-1]++;
        }
    }
    int ans=0;
    rep(i,N){
       if(sunuke[i]==0) ans++;
    }
     cout<<ans<<endl;   
   
}

