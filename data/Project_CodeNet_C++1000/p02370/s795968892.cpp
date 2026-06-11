#include <bits/stdc++.h>
using namespace std;

int v,e;
// hasparent
set<int> hp;
// children,parent
map<int,set<int>> c;
map<int,set<int>> p;
// topsort seq
vector<int> t;

int main(){
  cin>>v>>e;
  for(int i=0;i<e;i++){
    int a,b;cin>>a>>b;
    c[a].insert(b);
    p[b].insert(a);
  }
  for(int i=0;i<v;i++){
    if(p[i].empty())hp.insert(i);
  }
  while(hp.size()){
    int o=*hp.begin();
    t.push_back(o);
    hp.erase(hp.begin());
    for(auto h:c[o]){
      p[h].erase(o);
      if(p[h].empty())hp.insert(h);
    }
  }
  copy(t.begin(),t.end(),ostream_iterator<int>(cout,"\n"));
}