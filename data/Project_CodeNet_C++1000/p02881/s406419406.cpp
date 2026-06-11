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
  ll n; cin >> n;
  
  ll ans = 10000000000000000;
  rep(i, 1, pow(n, 0.5)+1){
    ll res;
    if(n % i == 0){res = i + n/i; ans = min(res, ans);}
  }
  
  cout << ans - 2 << endl;
}
      
