#include <bits/stdc++.h>
#define int long long 
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 998244353;

signed main() {
  int N;
  cin >> N;
  
  vector<int> A(N-1);
  vector<int> B(N-1);
  Graph G(N);
  for( int i = 0; i < N-1; i++ ){
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
    G.at(A.at(i)).push_back(B.at(i));
    G.at(B.at(i)).push_back(A.at(i));
  }
  
  int V = 0;
  int Vn = 0;
  for( int i = 0; i < N; i++ ){
    if( G.at(i).size() > Vn ){
      Vn = G.at(i).size();
    }
  }
  
  vector<int> dist(N, -1);
  queue<int> que;
  
  dist.at(0) = 1;
  que.push(0);
  
  while( !que.empty() ){
    int v = que.front();
    que.pop();
    
    int color = dist.at(v);
    for( int nv : G.at(v) ){
      if( dist.at(nv) != -1 ) continue; //すでに通っていたらスルー
      color++;
      if( color > Vn ) color = 1;
      dist.at(nv) = color;
      que.push(nv);
    }
  }
  cout << Vn << endl;
  for( int i = 0; i < N-1; i++ ){
    cout << dist.at(B.at(i)) << endl;
  }
}
