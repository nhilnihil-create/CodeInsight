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
    vector<ll>v(n);
    rep(i,n-1){
        cin>>v[i];
    }
  
    ll ans=0;
    
    rep(i,n){
        if(i==0)ans+=v[i];
        else if(i==n-1)ans+=v[n-2];
        else ans+=min(v[i],v[i-1]);
    }
    cout<<ans<<endl;
}
