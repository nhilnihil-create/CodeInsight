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
    rep(i,n)cin>>v[i];
    sort(v.begin(),v.end());
    long double now=0;
    rep(i,n){
        if(now==0)now=v[i];
        else{
            now=(now+v[i])/2.0;
        }
    }
     cout<<now<<endl;
}
