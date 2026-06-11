#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int k;
  cin >> k;
  if(k < 10){
    cout << k << endl;
    return 0;
  }
  queue<ll> q;
  rep2(i, 1, 10) q.push(i);
  rep(i, k-1){
    ll now = q.front(); q.pop();
    int m = now % 10;
    now *= 10;
    if(m != 0){
      q.push(now + m - 1);
    }
    q.push(now + m);
    if(m != 9){
      q.push(now + m + 1);
    }
  }
  cout << q.front() << endl;
  return 0;
}