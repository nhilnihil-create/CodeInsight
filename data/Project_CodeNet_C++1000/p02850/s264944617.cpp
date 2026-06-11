#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0;
  cin>>N;
  vector<vector<pair<int,int>>> g(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    g.at(a).push_back(make_pair(b,i));
    g.at(b).push_back(make_pair(a,i));
  }
  
  queue<pair<int,int>> q;
  vector<int> p(N-1);
  q.push(make_pair(0,0));
  while(!(q.empty())){
    int a=q.front().first,b=q.front().second;
    q.pop();
    int t=1;
    for(pair<int,int> x:g.at(a)){
      if(p.at(x.second)==0){
        if(t==b){
          t++;
        }
        p.at(x.second)=t;
        q.push(make_pair(x.first,t));
        t++;
      }
    }
  }
  for(int i=0;i<N-1;i++){
    Z=max(Z,p.at(i));
  }
  cout<<Z<<endl;
  for(int i=0;i<N-1;i++){
    cout<<p.at(i)<<endl;
  }
}