#include<bits/stdc++.h>
#define N 10005
using namespace std;

queue<int> S;// ??\???????????????????????¨???????????????
vector<int> in[N];// ??\??????
vector<int> out[N];// ?????????
vector<int> G[N];// ??\?????????????????????????????\???

void init(int V){// ?????°??????????????°
  for(int i=0;i<V;i++)in[i].clear();
  for(int i=0;i<V;i++){
    out[i]=G[i];
    for(int j=0;j<G[i].size();j++)
      in[G[i][j]].push_back(i);
  }
  for(int i=0;i<V;i++)
    if(!in[i].size())S.push(i);
}

vector<int> Topological_Sort(int V){
  vector<int> res;
  while(!S.empty()){
    int pos=S.front(); S.pop();
    res.push_back(pos);
    for(int i=0;i<out[pos].size();i++){
      int nx=out[pos][i];
      if(in[nx].size()==1)S.push(nx);
      for(int j=0;j<in[nx].size();j++)
	if(pos==in[nx][j]){
	  in[nx].erase(in[nx].begin()+j);
	  break;
	}
      out[pos].erase(out[pos].begin()+i);
      i--;
    }
  }
  for(int i=0;i<V;i++)
    if(in[i].size()||out[i].size())
      res.clear();
  return res;
}

int main(){
  int v,e,s,t;
  cin>>v>>e;
  for(int i=0;i<e;i++){
    cin>>s>>t;
    G[s].push_back(t);
  }
  init(v);
  vector<int> ans=Topological_Sort(v);
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
  return 0;
}