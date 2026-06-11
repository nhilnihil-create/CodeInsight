//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#include<algorithm>
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
#define all(x) x.begin(),x.end()
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;
    ll ac=0,wa=0;
    
    vector<pair<ll,string>> ps(100050);
    rep(i,m){
        cin>>ps[i].first>>ps[i].second;
    }

    vll a(100050);
    vll b(100050);

    rep(i,m){
        if(ps[i].second=="AC" && a[ps[i].first]==0) a[ps[i].first]=1;
        if(ps[i].second=="WA" && a[ps[i].first]==0) wa++;
    }

    rep(i,m){
        if(ps[i].second=="WA" && a[ps[i].first]==0){
            wa--;
        }
    }

    rep1(i,n) ac+=a[i];

    cout<<ac<<" "<<wa<<endl;
}