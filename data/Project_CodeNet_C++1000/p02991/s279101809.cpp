#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> graph(N);
  for(int i=0;i<M;i++){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    graph.at(u).push_back(v);
  }
  int S,T;
  cin >> S >> T;
  S--;
  T--;

  vector<vector<int>> dis(N,vector<int>(3,1e9));
  queue<pair<int,int>> que_cv;
  dis.at(S).at(0)=0;
  que_cv.push(make_pair(0,S));
  while(!que_cv.empty()){
    int c=que_cv.front().first;
    int v=que_cv.front().second;
    que_cv.pop();
    int nc=(c+1)%3;
    for(int i=0;i<graph.at(v).size();i++){
      int nv=graph.at(v).at(i);
      if(dis.at(nv).at(nc)!=1e9)  continue;
      dis.at(nv).at(nc)=dis.at(v).at(c)+1;
      que_cv.push(make_pair(nc,nv));
    }
  }
  if(dis.at(T).at(0)==1e9)  cout << -1 << endl;
  else  cout << dis.at(T).at(0)/3 << endl;

  return 0;
}