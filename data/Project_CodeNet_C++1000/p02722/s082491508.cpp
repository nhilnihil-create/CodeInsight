#include <bits/stdc++.h>
#include <set>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const long long INF = 1<<29;

const int MOD = 998244353;
long long ruizyou(long long m,long long n){
  if(m == 0)return 0;
  if(m == 1)return 1;
  long long ans = 1;
  long long tmp = m;
  for(int i=0;i<=30;i++){
    if(n & (1<<i)){
      ans *= tmp;
      ans %= MOD;
    }
    tmp *= tmp;
    tmp %= MOD;
  }
  return ans;
}
long long kaizyou(long long x){
  if(x == 0)return 1;
  return x * kaizyou(x-1) % MOD;
}
long long comb(long long x,long long y){
  long long bunsi = kaizyou(x);
  long long bunbo = kaizyou(x-y) * kaizyou(y) % MOD;
  return bunsi * ruizyou(bunbo,MOD-2) % MOD;
}
struct unionfind{
  vector<int> par;
  vector<int> hukasa;
  vector<int> kazu;
  unionfind(int n){
    par = vector<int>(n);
    hukasa = vector<int>(n,0);
    kazu = vector<int>(n,1);
    for(int i=0;i<n;i++){
      par.at(i) = i;
    }
  }
  int root(int x){
    if(par.at(x) == x)return x;
    return root(par.at(x));
  }
  void unite(int x,int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry)return;
    if(hukasa.at(rx) >= hukasa.at(ry)){
      par.at(ry) = rx;
      hukasa.at(rx) = max(hukasa.at(ry) + 1,hukasa.at(rx));
      kazu.at(rx) += kazu.at(ry);
    }
    else{
      par.at(rx) = ry;
      kazu.at(ry) += kazu.at(rx);
    }
  }
  void newkazu(){
    int n = kazu.size();
    for(int i=0;i<n;i++){
      kazu.at(i) = kazu.at(root(i));
    }
  }
  bool same(int x,int y){
    return root(x) == root(y);
  }
};
int ctoi(char a){
  return a - '0';
}
long long gcd(long long a,long long b){
  long long c = max(a,b);
  long long d = min(a,b);
  if(d % c == 0)return c;
  return gcd(c,d%c);
}
long long lcm(long long a,long long b){
  return a * b / gcd(a,b);
}
int main(){
  long long n;
  cin >> n;
  vector<long long> yakusu;
  for(long long i=2;i*i<=n;i++){
    if(n % i == 0){
      yakusu.push_back(i);
      if(i*i != n)yakusu.push_back(n/i);
    }
  }
  vector<long long> yakusu2;
  for(long long i=2;i*i<=n-1;i++){
    if((n-1) % i == 0){
      yakusu2.push_back(i);
      if(i*i != n-1)yakusu.push_back((n-1)/i);
    }
  }
  if(n>2)yakusu2.push_back(n-1);
  yakusu.push_back(n);
  long long ans = yakusu2.size();
  for(long long i:yakusu){
    long long tmp = n;
    while(tmp % i == 0)tmp /= i;
    if(tmp % i == 1)ans++;
  }
  cout << ans << endl;
}