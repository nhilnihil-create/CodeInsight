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
    map<string,ll> s;
    rep(i,n){
        string a;
        cin>>a;
        s[a]++;
    }
    ll mn=0;
    for(auto p:s)mn=max(mn,p.second);
    for(auto p:s){
        if(p.second==mn)cout<<p.first<<endl;
    }
    }
