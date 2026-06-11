#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
  ll n; cin >> n;
  vll a(n);
  rep(i, 0, n){cin >> a[i];}
  
  vll f(n,0);
  rep(i, 0, n){
    f[0] += pow(-1, i) * a[i];
  }
  
  rep(i, 1, n){
    f[i] = f[i-1] * (-1) + 2 * a[i-1];
  }
  
  for(auto x:f){cout << x << " ";}
}

