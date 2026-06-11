#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1){}
  void add(int i,T x=1){
    for(i++;i<=n;i += i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for(i++;i>0;i -= i&-i){
      x += d[i];
    }
    return x;
  }
};
 
int main(){
  int n,d,a;cin >> n >> d >> a;
  vector<pair<ll,ll>> enemy(n);
  rep(i,n) cin >> enemy[i].first >> enemy[i].second;
  sort(enemy.begin(),enemy.end());
  vector<ll> bpos,damage;
  BIT<ll> tree(200005);
  bpos.push_back(enemy[0].first+2*d);
  tree.add(0,(enemy[0].second+a-1)/a*a);
  ll ans = (enemy[0].second+a-1)/a;
  for(int i = 1;i < n;i++){
    int ind = lower_bound(bpos.begin(),bpos.end(),enemy[i].first) - bpos.begin();
    ll sum = tree.sum(bpos.size()-1) - ((ind > 0) ? tree.sum(ind-1) : 0);
    // for(int j = ind;j < bpos.size();j++){
    //   sum += damage[j];
    // }
    if(sum >= enemy[i].second) continue;
    sum = enemy[i].second - sum;
    bpos.push_back(enemy[i].first + 2*d);
    tree.add(bpos.size()-1,(sum+a-1)/a*a);
    ans += (sum+a-1)/a;
  }
  cout << ans << endl;

  
}