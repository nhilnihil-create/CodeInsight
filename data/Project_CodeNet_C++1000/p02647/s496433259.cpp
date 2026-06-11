#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = int;
using vi = vector<ll>;
using vvi = vector<vi>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

//ll INF = 1ll << 60;

void chmin(ll &a, ll b){
  if(a > b)
    a = b;
}
void chmax(ll &a, ll b){
  if(a < b)
    a = b;
}

int main(){
  ll n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, 0, n)
    cin >> a[i];
  
  rep(i, 0, k){
    vi b(n, 0);
    rep(j, 0, n){
      ll l, r;
      l = max(0, j-a[j]);
      r = min(n-1, j+a[j]);
      b[l]++;
      if(r+1 < n)
        b[r+1]--;
    }
    
    rep(j, 1, n)
        b[j] += b[j-1];
    
    a = b;
    
    bool c = true;
    
    rep(j, 0, n){
      if(a[j] != n)
        c = false;
    }
    if(c)
      break;
    
  }
  
  rep(i, 0, n)
    cout << a[i] << " ";
  cout << endl;
  
  return 0;
  
}