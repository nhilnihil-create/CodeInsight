#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  set<tuple<int,int,int>> e;
  for(int i=0; i<N-1; i++){
    int a,b; cin >> a >> b;
    e.insert(make_tuple(a,b,i));
    e.insert(make_tuple(b,a,i));
  }
  
  // 頂点1から始める
  // 1につないでいる辺に1から振る
  // 振った辺の先の頂点でそれぞれ1から振る（ただし元の数字は飛ばす）
  // 振った中でmaxが最小
  int maxcolor=0;
  vector<int> ecolor(N-1,0);
  queue<pair<int,int>> q; // 頂点/色
  q.push(make_pair(1,0));
  while(!e.empty()){
    pair<int,int> v=q.front(); q.pop();
    int currentcolor=0;
    auto itr=e.lower_bound(make_tuple(v.first,0,0));
    while(get<0>(*itr)==v.first){
      currentcolor++;
      if(currentcolor==v.second) currentcolor++;
      if(maxcolor<currentcolor) maxcolor=currentcolor;
      ecolor[get<2>(*itr)]=currentcolor;
      q.push(make_pair(get<1>(*itr),currentcolor));
      e.erase(e.find(make_tuple(get<1>(*itr),get<0>(*itr),get<2>(*itr))));
      itr=e.erase(itr);
    }
  }
  cout << maxcolor << endl;
  for(int i=0; i<N-1; i++) cout << ecolor[i] << endl;
}