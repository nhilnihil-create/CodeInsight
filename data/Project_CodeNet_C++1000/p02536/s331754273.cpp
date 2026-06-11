#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

// UnionFind木
const int MAX = 100010;
int par[MAX];

void init(){
  rep(i, 0, MAX){
    par[i] = -1;
  }
}

int root(int x){
  if(par[x] < 0){
    return x;
  }
  return par[x] = root(par[x]);
}

int size(int x){
  return -par[root(x)];
}

void unite(int x, int y){
  int rx = root(x);
  int ry = root(y);
  if(rx == ry){
    return;
  }
  if(size(rx) < size(ry)){
    swap(rx, ry);
  }
  par[rx] += par[ry];
  par[ry] = rx;
  return;
}

bool same(int x, int y){
  int rx = root(x);
  int ry = root(y);
  if(rx < 0 || ry < 0){
    if(rx >= 0){
      return rx == y;
    }
    if(ry >= 0){
      return ry == x;
    }
    return false;
  }
  return rx == ry;
}

int main(){
  int n, m;
  cin >> n >> m;
  
  init();
  
  rep(i, 0, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    unite(a, b);
  }
  
  vb ck(n, false);
  
  rep(i, 0, n)
    ck[root(i)] = true;
  
  int cnt = 0;
  
  rep(i, 0, n){
    if(ck[i])
      cnt++;
  }
  
  cout << cnt-1 << endl;
  
  return 0;
  
}