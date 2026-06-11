#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using pint = pair<int,int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main() {
    int n;cin>>n;
    vector<int> d(n);
    rep(i,n) cin>>d[i];
    sort(d.begin(),d.end());

    cout<<d[d.size()/2]-d[d.size()/2-1]<<endl; 
}