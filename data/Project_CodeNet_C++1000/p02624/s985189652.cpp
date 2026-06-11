#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

vector<ll>Sieve(long long n){
  vector<ll>table(n+1,1);
  for(long long i = 2;i <= n;i++){
    if(table[i] == 1){
      for(ll j = i;j <= n;j += i){
        ll k = j,cnt = 1;
        while(1){
          k /= i;
          if(k%i != 0 || k == 1) break;
          cnt += 1;
        }
        table[j] *= cnt+1;
      }
    }
  }
  return table;
}

int main() {
  ll n,ans = 0;
  cin >> n;
  vector<ll>data = Sieve(n);
  rep(i,1,n+1){
    //cout << data[i] << endl;
    ans += data[i]*i;
  }
  cout << ans << endl;
}