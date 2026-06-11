#include <iostream>
#include <vector>
using namespace std;

vector<int> p;
vector<int> rank;

int find(int x){
  if(x != p[x]){
    p[x] = find(p[x]);
  }
  return p[x];
}

void link(int x, int y){
  if(rank[x] > rank[y]){
    p[y] = x;
  }else{
    p[x] = y;
    if(rank[x] == rank[y]){
      rank[y]++;
    }
  }
}
void unite(int x, int y){
  link(find(x), find(y));
}
bool same(int x, int y){
  return find(x) == find(y);
}

int main(void){
  int n, q;
  cin >> n >> q;
  p.resize(n, 0);
  rank.resize(n, 0);
  for(int i=0; i < n; i++){ p[i] = i; rank[i] = 0; }
  while(q--){
    int com, x, y; cin >> com >> x >> y;
    if(com == 0) unite(x, y);
    else{
      if(same(x, y)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
  return 0;
}