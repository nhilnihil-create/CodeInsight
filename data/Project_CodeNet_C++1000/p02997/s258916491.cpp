#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;

int main(){
  int N,K;
  cin>>N>>K;
  if(!(0<=K && K<=(N-2)*(N-1)/2)){
    cout<<-1<<endl;
    return 0;
  }
  
  
  vector<P>ans;
  //ウニの構築
  for(int i=2;i<=N;i++){
    ans.push_back(P(1,i));
  }
  //ちょうどK個になるよう減らす
  vector<P>ve;
  for(int i=2;i<=N;i++){
    for(int j=i+1;j<=N;j++){
      ve.push_back(make_pair(i,j));
    }
  }
  for(int i=0;i<(N-2)*(N-1)/2-K;i++){
    ans.push_back(ve[i]);
  }
  
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  } 
  return 0;
}


