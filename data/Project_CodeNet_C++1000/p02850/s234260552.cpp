#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
int main(){
int N; cin>>N;map<pair<int,int>,int>M;
  Graph G(N);
  for(int i=0;i<N-1;i++){
  int a,b; cin>>a>>b; a--;b--;
    pair<int,int>p1(a,b); pair<int,int>p2(b,a);
    M[p1]=i; M[p2]=i;
    G[a].push_back(b);
    G[b].push_back(a);
  }int Max=G[0].size();
  int a=0;
  for(int i=1;i<N;i++){
  int Size=G[i].size();
    if(Max<Size){a=i; Max=Size;}
  }queue<int>que;
  que.push(a);
  vector<int>color(N-1);
  vector<int>Color(N,-1);
  Color.at(a)=0;
  while(!que.empty()){
  int u=que.front();
    que.pop();
    int k=-1;
    for(auto v:G[u]){
    
      if(Color.at(v)!=-1)
        continue;
      else{
        k++;
      int b=1+(Color.at(u)+k)%Max;
      Color.at(v)=b;
        pair<int,int>p(u,v);
       int c= M.at(p);
         color.at(c)=b;
        que.push(v);
      }
    }
   }cout<<Max<<endl;
  for(int i=0;i<N-1;i++)
    cout<<color.at(i)<<endl;
   return 0;
}