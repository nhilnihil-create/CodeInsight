#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<int>> &nl, vector<int> &ct) {
  for(int i = 0; i < nl.at(x).size(); i++) {
    //隣接リストの要素が親(y)の場合は飛ばす
    if(nl.at(x).at(i) == y) {
      continue;
    }
    else {
      //それぞれの要素に自分のカウンター数（ct.at(x)を配る
      ct.at(nl.at(x).at(i)) += ct.at(x);
      //新たな要素についてDFS　親は現在のノード(x)
      dfs(nl.at(x).at(i), x, nl, ct);
    }
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> nl(N);
  
  //隣接リスト入力
  
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    nl.at(a - 1).push_back(b - 1);
    nl.at(b - 1).push_back(a - 1);
  }
  
  //カウンター加算
  
  vector<int> ct(N);
  for(int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    ct.at(p - 1) += x;
  }
  
  //ノード　0 親　-1　からDFS
  
  dfs(0, -1, nl, ct);
  
  for(int i = 0; i < N-1; i++) {
    cout << ct.at(i) << " ";
  }
  cout<<ct.at(N-1)<<endl;
}

