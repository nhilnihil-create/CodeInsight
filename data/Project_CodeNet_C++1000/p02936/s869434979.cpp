#include<bits/stdc++.h>
using namespace std;
typedef long int li;
#define pb push_back
#define SZ(x) ((int)(x).size())

int N, Q, x, y;
vector<vector<int>> tree(200010, vector<int>());  //頂点関係
vector<int> par(200010, 0);  //頂点の親
vector<li> counter(200010, 0);  //カウンター


void add_counter(int v, int p, li cn_p){
  counter[v] += cn_p;  //vにcn_p分を伝搬
  for(int i = 0; i < SZ(tree[v]); i++){
    int chi_v = tree[v][i];
    if(chi_v == p) continue;
    par[chi_v] = v;
    add_counter(chi_v, v, counter[v]);
  }
  return;
}


int main(){
  cin >> N >> Q;
  
  /*以下、辺を取得*/
  for(int i = 0; i < N-1; i++){ 
    cin >> x >> y;
    tree[x].pb(y); tree[y].pb(x);
  }
  
  /*以下、カウンタを取得*/
  for(int i = 0; i < Q; i++){
    cin >> x >> y;
    counter[x] += y;  //xに加えるカウンタ数
  }
  
  add_counter(1, 0, 0);
  
  for(int i = 1; i <= N; i++) cout << counter[i] << endl;
  return 0;
}
