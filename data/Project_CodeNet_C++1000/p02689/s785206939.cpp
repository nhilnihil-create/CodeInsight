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
  ll n, m;
  cin >> n >> m;
  
  vll height (n+1);
  rep(i, 1, n+1){
    cin >> height[i];
  }
  
  vector<vector<pll>> connect (n+1,vector<pll>(0));
  rep(i, 0, m){
    ll a, b; cin >> a >> b;
    connect[a].emplace_back(pll(height[b],b));
    connect[b].emplace_back(pll(height[a],a));
  }
  
  ll ans = 0;
  rep(i, 1, n+1){
    sort(connect[i].begin(),connect[i].end());
    reverse(connect[i].begin(),connect[i].end());
    
    if(connect[i].size() == 0){ans++; continue;}
    else{
      if(height[i] > connect[i][0].first){ans++; continue;}
    }
  }
  
  cout << ans << endl;
    
}




