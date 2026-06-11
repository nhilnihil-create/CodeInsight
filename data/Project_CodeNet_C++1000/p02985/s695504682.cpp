#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

#define MOD 1000000007

void show(vector<ll>* g, ll s, ll from) {
  cout << from << " -> " << s << endl;
  rep(i,g[s].size()) {
    if(g[s][i] != from) show(g,g[s][i],s);
  }
}


ll calc(vector<ll>* g, ll s, ll from, ll k) {
  ll color_num,child_num;
  if(from==-1) {
    color_num = k-1;
    child_num = g[s].size();
  }else {
    color_num = k-2;
    child_num = g[s].size()-1;
  }

  if(child_num>color_num) return 0;
  
  ll sum = 1;
  rep(i,g[s].size()) {
    if(g[s][i] == from) continue;
    
    sum *= color_num; if(sum==0) break;
    sum %= MOD;
    color_num--;
  }
  rep(i,g[s].size()) {
    if(g[s][i] == from) continue;
    
    sum *= calc(g,g[s][i],s,k); if(sum==0) break;
    sum %= MOD;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  ll n,k;
  ll x,y;
  vector<ll> *g;
  
  cin >> n >> k;
  g = new vector<ll>[n];
  rep(i,n-1) {
    cin >> x >> y;
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
  }

  //show(g,0,-1);

  ll ans = k*calc(g,0,-1,k);
  ans %= MOD;
  cout << ans << endl;;
  

  delete[] g;
  
  return 0;
}
