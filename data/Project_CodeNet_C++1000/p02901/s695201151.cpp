#include <bits/stdc++.h>
using namespace std;
int ni(int a){
  int b=1;
  for(int i=0;i<a;i++){
    b*=2;
  }
  return b;
}
int main() {
  int N,M;
  cin>>N>>M;
  vector<int> p(M);
  vector<int> c(M);
  for(int i=0;i<M;i++){
    int x,y;
    cin>>x>>y;
    c.at(i)=x;
    int b=0;
    for(int i=0;i<y;i++){
      int a;
      cin>>a;
      a--;
      b+=ni(a);
    }
    p.at(i)=b;
  }
  int Q=ni(N);
  vector<vector<int>> dp(M+1,vector<int>(Q,1000000001));
  dp.at(0).at(0)=0;
  for(int i=0;i<M;i++){
    for(int j=0;j<Q;j++){
      dp.at(i+1).at(j)=dp.at(i).at(j);
    }
    for(int j=0;j<Q;j++){
      dp.at(i+1).at(j|p.at(i))=min(dp.at(i+1).at(j|p.at(i)),dp.at(i).at(j)+c.at(i));
    }
  }
  if(dp.at(M).at(Q-1)==1000000001){
    cout<<"-1"<<endl;
  }
  else{
    cout<<dp.at(M).at(Q-1)<<endl;
  }
}