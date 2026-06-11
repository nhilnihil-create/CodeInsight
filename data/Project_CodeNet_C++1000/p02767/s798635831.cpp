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
    cin >>n;
    vector<ll>x(n);
    rep(i,n){
        cin>>x[i];
    }
    ll ans=10000000;
    ll sum=0;
    rep(i,101){
        sum=0;
        rep(l,n){
           sum+=pow(llabs((x[l]-i)),2); 
        }
       ans=min(ans,sum);
    }
    cout<<ans<<endl;
}

