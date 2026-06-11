#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N+1);
  for(int i=1;i<=N;i++)cin>>A[i];
  vector<int>b(N+1);
  for(int i=N;i>=1;i--){
    int sum=0;
    for(int j=i*2;j<=N;j+=i){
      sum^=b[j];
    }
    b[i]=sum^A[i];
  }
  vector<int>ans;
  for(int i=1;i<=N;i++){
    if(b[i])ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}