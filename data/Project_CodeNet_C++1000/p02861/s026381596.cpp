#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const int INF = 1<<29;

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

int main(){
  int n;
  cin >> n;
  vector<vector<int>> point(n,vector<int>(2));
  for(int i=0;i<n;i++){
    cin >> point.at(i).at(0) >> point.at(i).at(1);
  }
  sort(point.begin(),point.end());
  double ans = 0;
  do{
    double tmp = 0;
    for(int i=1;i<n;i++){
      int x1 = point.at(i-1).at(0),y1 = point.at(i-1).at(1);
      int x2 = point.at(i).at(0),y2 = point.at(i).at(1);
      tmp += pow((pow(x1-x2,2) + pow(y1-y2,2)),0.5);
    }
    ans += tmp;
  }
  while(next_permutation(point.begin(),point.end()));
  cout << fixed << setprecision(10) << ans/kaizyou(n) << endl;
}