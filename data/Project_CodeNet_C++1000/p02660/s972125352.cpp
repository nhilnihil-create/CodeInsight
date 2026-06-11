#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

ll pow(ll x,ll y){
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  if(y%2 == 0){
    return pow(x,y/2)*pow(x,y/2);
  }
  else{
    return x*pow(x,y/2)*pow(x,y/2);
  }
}
struct Sieve {
  int n;
  vector<int> mindivnum, primes;
  Sieve(int n=1):n(n), mindivnum(n+1) {
    mindivnum[0] = mindivnum[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (mindivnum[i]) continue;
      primes.push_back(i);
      mindivnum[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!mindivnum[j]) mindivnum[j] = i;
      }
    }
  }
  bool isPrime(int x) { return mindivnum[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(mindivnum[x]);
      x /= mindivnum[x];
    }
    return res;
  }
  vector<pair<int,int>> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<pair<int,int>> res(1, pair<int,int>(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
}; 

int main(){
    ll n;
    cin >> n;
    Sieve s(1000000);
    auto fs = s.factor(n);
    int ans = 0;
    for(auto p: fs){
        int a = p.second;
        int b = 1;
        while(a>=b){
            a-=b;
            b++;
            ans++;
        }
    }
    cout << ans << endl;
}