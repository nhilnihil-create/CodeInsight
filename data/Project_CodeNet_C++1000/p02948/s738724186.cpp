#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
int main(){
  ll N,M;
  cin>>N>>M;
  vector<vector<int>>Data(100010);
  for(int i=0;i<N;i++){
    int A,B;
    cin>>A>>B;
    Data[A].push_back(B);
  }
  priority_queue<int>que;
  int ans=0;
   for(int i=1;i<=M;i++){
    for(auto a:Data[i]){
      que.push(a);
    }
    if(!que.empty()){
    ans+=que.top();
    que.pop();
    }
    //cnt--;
    //if(cnt==-1)break;
  }
  cout<<ans<<endl;
}
