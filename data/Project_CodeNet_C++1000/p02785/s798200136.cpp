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
    ll n,k;
    cin>>n>>k;
    vector<ll>h(n);
    rep(i,n)cin>>h[i];
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    k=min(n,k);
    rep(i,k)h[i]=0;
    ll sum=0;
    rep(i,n)sum+=h[i];
    cout<<sum<<endl;
    }
