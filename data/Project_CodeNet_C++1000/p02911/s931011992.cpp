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
    ll a,b,c;
    cin>>a>>b>>c;
    map<ll,ll>mp;
    rep(i,c){
     ll d;
     cin>>d;
     mp[d-1]++;
    }
    rep(i,a){
        if(0<mp[i]+b-c)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
