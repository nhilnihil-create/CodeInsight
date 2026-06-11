#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<vector<pair<int,int>>> G(N);
  vector<int> c(N-1);
  vector<int> S(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    S.at(a)++,S.at(b)++;
    G.at(a).push_back(make_pair(b,i));
    G.at(b).push_back(make_pair(a,i));
  }
  int Z=0;
  for(int i=0;i<N;i++){
    Z=max(Z,S.at(i));
  }
  cout<<Z<<endl;
  queue<pair<int,int>> q;
  q.push(make_pair(0,-1));
  while(!q.empty()){
    int a,b;
    tie(a,b)=q.front();
    q.pop();
    int t=1;
    for(pair<int,int> x:G.at(a)){
      if(t==b){
        t++;
      }
      int d,e;
      tie(d,e)=x;
      if(c.at(e)==0){
        c.at(e)=t;
        q.push(make_pair(d,t));
        t++;
      }
    }
  }
  for(int i=0;i<N-1;i++){
    cout<<c.at(i)<<endl;
  }
}