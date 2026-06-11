#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> k(n-1);
  for(long long i = 1; i <= n-1; i++){
    for(long long j = i+1; j <= n; j++){
      ll p, q;
      p = j - i;
      q = (max(x,i)-min(x,i))+(max(y,j)-min(y,j))+1;
      
      k[min(p,q)-1]++;
    }
  }
  rep(i,n-1){
    cout << k[i] << endl;
  }
  return 0;
}