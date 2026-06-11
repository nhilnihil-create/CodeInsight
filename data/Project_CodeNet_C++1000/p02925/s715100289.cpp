#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> g(n*n);
  vector<int> p(n*n,0);
  for(int i=0;i<n;i++){
    vector<int> v(n-1);
    for(int j=0;j<n-1;j++){
      int a;
      cin>>a;
      a--;
      v.at(j)=min(i,a)*n+max(i,a);
    }
    for(int j=1;j<n-1;j++){
      g.at(v.at(j-1)).push_back(v.at(j));
      p.at(v.at(j))++;
    }
  }
  vector<int> l(n*n,-1);
  queue<int> q;
  for(int i=0;i<n*n;i++)
    q.push(i);
  for(int i=0;i<n*n&&!q.empty();i++){
    vector<int> s;
    while(!q.empty()){
      int v=q.front();
      q.pop();
      if(p[v]!=0||i<=l[v])
        continue;
      l[v]=i;
      s.push_back(v);
    }
    for(int x:s){
      for(int y:g.at(x)){
        q.push(y);
        p[y]--;
      }
    }
  }
  bool f=1;
  int m=0;
  for(int i=0;i<n*n;i++){
    f=(l[i]==-1?0:f);
    m=max(m,l[i]);
  }
  cout<<(f?m+1:-1)<<endl;
}