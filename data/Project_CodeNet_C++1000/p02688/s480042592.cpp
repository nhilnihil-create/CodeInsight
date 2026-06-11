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
  ll n, k;
  cin >> n >> k;
  
  vll okashi (n+1, 0);
  
  rep(i, 0, k){
    ll d; cin >> d;
    rep(j, 0, d){
      ll a; cin >> a;
      okashi[a]++;
    }
  }
  
  ll ans = 0;
  rep(i, 1, n+1){
    if(okashi[i] == 0){ans++;}
  }
  
  cout << ans << endl;
}




