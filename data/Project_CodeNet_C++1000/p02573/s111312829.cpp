#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> par;
vector<int> siz;
int maxi=1;

int root(int x){
  if(par.at(x)==-1) return x;
  return par.at(x) = root(par.at(x));
}

int size(int x){
  return siz.at(x);
}

void unite(int x, int y){
  x = root(x);
  y = root(y);
  
  if(x==y) return;
  if(size(x) < size(y)) swap(x, y);
  par.at(y) = x;
  siz.at(x) += size(y);
  maxi = max(maxi, size(x));
}

int main() {
  int N, M;
  cin >> N >> M;
  par.assign(N, -1);
  siz.assign(N, 1);
  int a, b;
  rep(i, M){
    cin >> a >> b;
    --a; --b;
    unite(a, b);
  }
  
  cout << maxi << endl;
  
  return 0;
}


