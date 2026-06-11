#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>P(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>P[i];
  }
  int min=P[0];
  int ans=1;
  for(int i=1;i<=N-1;i++){
  
    if(min>=P[i]){
    
      ans++;
      min=P[i];
    }
  }
  cout<<ans;
}