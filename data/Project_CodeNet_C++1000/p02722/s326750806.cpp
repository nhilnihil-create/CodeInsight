#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// Sieve of Eratosthenes
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};
ll n;
bool solve(ll y){
    ll temp = n;
    while(temp%y==0){
        temp/=y;
    }
    temp%=y;
    if(temp==1){
        return true;
    }
    return false;
}
vector<ll> f(ll n){
    vector<ll> factor;
    for(ll i=1;i*i<=n;i++){
        if(n%i!=0)continue;
        factor.push_back(i);
        if(i*i!=n)factor.push_back(n/i);
    }
    return factor;
}

int main(){
    cin >> n;
    Sieve si(1e6);
    vector<ll> fo;
    fo=f(n-1);
    vector<ll> po;
    po=f(n);
    ll ans = fo.size();
    ans--;
    rep(i,po.size()){
        if(po[i]==1)continue;
        if(solve(po[i]))ans++;
    }
    cout << ans << endl;
    return 0;
}
