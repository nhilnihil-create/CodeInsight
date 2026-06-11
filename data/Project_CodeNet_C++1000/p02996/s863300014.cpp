#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  vector<pair<int,int>> tasks;
  for(int i=0;i<N;i++){
    int a,b;cin>>a>>b;
    tasks.emplace_back(b,a);
  }
  sort(tasks.begin(),tasks.end());
  int flow=0;
  bool can=true;
  for(auto v :tasks){
    flow += v.second;
    if(flow>v.first){
      can =false;
      break;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}