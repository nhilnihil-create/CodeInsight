#include<bits/stdc++.h>
using namespace std;
int N,M,a,b,ans;
int main(){
  cin>>N>>M;
  vector<vector<int>>v(1<<17);
  for(int i=0;i<N;i++){
    cin>>a>>b;
    v[a].push_back(b);
  }
  priority_queue<int>q;
  for(int i=1;i<=M;i++) {
    for(auto e:v[i])q.push(e);
    if(q.size())ans+=q.top(),q.pop();
  }
  cout<<ans<<endl;
}
