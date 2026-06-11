#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,ans=0;
  cin>>N>>M;
  unordered_map<int,vector<int>> mp;
  priority_queue<int> q;
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
    if(a==1){q.push(b);}
  }
  for(int i=1;i<=M;i++){
    if(!q.empty()){
      ans+=q.top();
      q.pop();
    }
    if(i==M){break;}
    for(int j=0;j<(int)mp[i+1].size();j++){
      q.push(mp[i+1].at(j));
    }
  }
  cout<<ans<<endl;
}