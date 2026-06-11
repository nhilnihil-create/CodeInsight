#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

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
  vector<ll> factorList(ll x) {
    vector<ll> res;
    for (int p : primes) {
      while (x%p == 0) {
        res.push_back(p);
        x /= p;
      }
    }
    if (x != 1) res.push_back(x);
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {  //firstが素因数
    vector<ll> fl = factorList(x);  //secondがそれが何個あるか
    if (fl.size() == 0) return {};
    vector<pair<ll,int>> res(1, P(fl[0], 0));
    for (ll p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main() {
    ll n;
    cin >> n;
    Sieve s(1000005); //Sieveというデータ構造を使う。名前をsとする。
    auto fs = s.factor(n); //sの中の関数factorを使う。factor(n)でnの<素因数,その数>を配列で返す。
    int ans = 0;
    for(auto p : fs){
        int x = p.second;
        int b = 1;
        while(b <= x){
            x -= b;
            b++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}