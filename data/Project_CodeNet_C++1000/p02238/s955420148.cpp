#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
  vector<int> G[100];
  stack<int> q;
  vector<int> d(100,200000000),f(100,200000000);
  int n,u,k,v,time=0;
  bool flg;
  
  cin >> n;
  //G.push_back(new vector<int>(,10));
  for (int i=0;i<n;i++){
    cin >> u>> k;
    for (int j=0;j<k;j++){
      cin >> v;
      G[u-1].push_back(v-1);
    }
  }
  for (int vi=0;vi<n;vi++){
    if (d[vi]<=time)continue;
    q.push(vi);
    d[vi]=++time;
    while (!q.empty()){
      u=q.top();
      for (int i=0;i<G[u].size();i++){
	v=G[u][i];
	if (d[v]>time){
	  q.push(v);
	  d[v]=++time;
	  flg=true;
	  break;
	}
      }
      if (!flg){
	q.pop();
	f[u]=++time;
      }else{
	flg=false;
      }
    }
    
  }
  for (int i=0;i<n;i++)
    cout << i+1 <<" "<< d[i]<<" "<<f[i]<<endl;
  
  return 0;
}