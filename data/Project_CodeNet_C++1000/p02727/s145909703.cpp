#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const long long INF = 1<<29;

const int MOD = 1000000007;
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
  return bunsi * ruizyou((int)bunbo,MOD-2) % MOD;
}
struct unionfind{
  vector<int> par;
  vector<int> hukasa;
  unionfind(int n){
    par = vector<int>(n);
    hukasa = vector<int>(n,0);
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
    }
    else{
      par.at(rx) = ry;
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
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a),q(b),r(c);
  for(int i=0;i<a;i++)cin >> p.at(i);
  for(int i=0;i<b;i++)cin >> q.at(i);
  for(int i=0;i<c;i++)cin >> r.at(i);
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  sort(q.begin(),q.end());
  reverse(q.begin(),q.end());
  sort(r.begin(),r.end());
  reverse(r.begin(),r.end());
  int aa = x-1,bb = y-1,cc = 0;
  while(cc < c){
    if(aa>=0 && bb>=0){
      if(r.at(cc) > min(p.at(aa),q.at(bb))){
        cc++;
        if(p.at(aa) < q.at(bb))aa--;
        else bb--;
      }
      else break;
    }
    else if(bb >= 0){
      if(r.at(cc) > q.at(bb)){
        cc++;
        bb--;
      }
      else break;
    }
    else if(aa >= 0){
      if(r.at(cc) > p.at(aa)){
        cc++;
        aa--;
      }
      else break;
    }
    else break;
  }
  long long ans = 0;
  for(int i=0;i<=aa;i++)ans += p.at(i);
  for(int i=0;i<=bb;i++)ans += q.at(i);
  for(int i=0;i<cc;i++)ans += r.at(i);
  cout << ans << endl;
}