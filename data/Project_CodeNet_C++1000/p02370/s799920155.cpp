#include<iostream>
#include<vector>
#include<queue>
using namespace std;
main(){
  ios_base::sync_with_stdio(false);
  int v,e,s,t,lose[10001];
  vector<int> vec[10001];
  queue<int> que;
  cin >> v >> e;
  for(int i=0;i<e;i++){
    cin >> s >> t;
    lose[t]++;
    vec[s].push_back(t);
  }
  for(int i=0;i<v;i++){
    if(lose[i] == 0) que.push(i);
  }
  while(!que.empty()){
    int point = que.front();
    que.pop();
    cout << point << endl;
    for(int i=0;i<vec[point].size();i++){
      lose[vec[point][i]]--;
      if(!lose[vec[point][i]]) que.push(vec[point][i]);
    }
  }
  return(0);
}

