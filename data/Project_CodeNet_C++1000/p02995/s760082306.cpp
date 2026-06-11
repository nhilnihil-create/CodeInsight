#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
ll gcd(ll a, ll b){
  if(a < b){
    return gcd(b,a);
  }
  if(a % b ==0){
    return b;
  }
  else{
    return gcd(b,a%b);
  }
}
ll lcm(ll a, ll b){
  return a*b/gcd(a,b);
}
ll a_div_num(ll p,ll q,ll r){//1~rまででpでもqでも割れない個数
  ll np = ll(r/p);
  ll nq = ll(r/q);
  ll pkatsuq = ll(r/(lcm(p,q)));
  return r - (np + nq -pkatsuq);
}
int main() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << a_div_num(c,d,b) - a_div_num(c,d,a-1) << endl;
  return 0;
}