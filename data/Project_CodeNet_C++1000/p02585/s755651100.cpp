#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

int main(){
  ll n, k;
  cin >> n >> k;
  vl p(n), c(n);
  rep(i, 0, n){
    cin >> p[i];
    p[i]--;
  }
  rep(i, 0, n)
    cin >> c[i];
  
  ll ans = -INF;
  
  rep(i, 0, n){
    int v = i;
    ll cycle_sum = 0;
    int cycle_cnt = 0;
    
    while(true){
      cycle_cnt++;
      cycle_sum += c[v];
      v = p[v];
      
      if(i == v)
        break;
    }
    
    ll path = 0;
    int cnt = 0;
    
    while(true){
      cnt++;
      path += c[v];
      
      if(cnt > k)
        break;
      
      int num = (k-cnt)/cycle_cnt;
      ll score = path + max(0LL, cycle_sum)*num;
      ans = max(ans, score);
      
      v = p[v];
      if(v == i)
        break;
    }
  }
  
  cout << ans << endl;
  
  return 0;
  
}