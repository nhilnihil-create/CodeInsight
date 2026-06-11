#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll h,w,k; cin >> h >> w >> k;
  vector<string> grid(h);
  rep(i, h)
      cin >> grid[i];
  
  ll cnt = 0;
 
  rep(i, 1<<h){ rep(j, 1<<w){
      ll sum = 0;
      rep(m, h){ rep(n, w){
          if((1<<m)&i) continue;
          if((1<<n)&j) continue;
          if(grid[m][n] == '#') sum ++;
      }}
    if (sum == k)
      cnt++;
  }}
 
  cout << cnt << endl;
}