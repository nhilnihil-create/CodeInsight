#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Sieve {
  vector<int> f, primes; // primesは素数集合，fは合成数に素因数を一つ示したもの
  Sieve(int N):f(N+1,0) {
    f[0] = f[1] = -1;
    for (int i = 2; i <= N; ++i) {
      if (!f[i]==0){
        continue;
      }
      primes.push_back(i);
      f[i] = i;
      if(i>sqrt(N)){
        continue;
      }
      for (int j = i*i; j <= N; j += i) {
        if (f[j]==0){
          f[j] = i;
        }
      }
    }
  }

  bool isPrime(int x) { //xが素数かどうかを判断するメンバ関数
    return f[x] == x;
  }

  vector<int> factorList(int x) { //xの素因数を小さい順ソートされた配列
    vector<int> res;
    if(x==0 || x==1){
      return { };
    }
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }

  vector<pair<int,int>> factor(int x) { //xのfactorListをランレングス圧縮したもの
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<pair<int,int>> res(1, make_pair(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      }
      else {
        res.push_back(make_pair(p, 1));
      }
    }
    return res;
  }

  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0){
        x /= p, ++y;
      }
      if (y != 0){
        res.push_back(make_pair(p,y));
      }
    }
    if (x != 1){
      res.push_back(make_pair(x,1));
    }
    return res;
  }
};

int main(){
  ll N;
  cin >> N;
  Sieve S(1e6+5);
  vector<pair<ll,int>> fac=S.factor(N);
  ll ans=0;
  for(pair<ll,int>  p: fac){
    ans+=floor((-1+sqrt(1+8*p.second))/2);
  }
  cout << ans << endl;
}