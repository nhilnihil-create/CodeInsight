#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
  ll x; cin >> x;
  bool f = false;
  rep(i, -120, 121){
    rep(j, -120, 121){
      if(pow(i, 5) - pow(j, 5) == x){cout << i << " " << j << endl; f = true; break;}
    }
    if(f){break;}
  }
      
    
}




