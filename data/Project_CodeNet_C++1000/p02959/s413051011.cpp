#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>monster(N+1);
  vector<int>hero(N);
  for(int i=0;i<=N;i++){
  
    cin>>monster[i];
  }
  for(int i=0;i<=N-1;i++){
  
    cin>>hero[i];
  }
  long long ans=0;
  for(int i=0;i<=N-1;i++){
  
    if(hero[i]>=monster[i]){
    
      ans+=monster[i];
      hero[i]-=monster[i];
      monster[i]=0;
      if(hero[i]>=monster[i+1]){
      
        ans+=monster[i+1];
        hero[i]-=monster[i+1];
        monster[i+1]=0;
      }
      else{
      
        monster[i+1]-=hero[i];
        ans+=hero[i];
        hero[i]=0;
      }
    }
    else{
    
      ans+=hero[i];
      monster[i]-=hero[i];
      hero[i]=0;
    }
  }
  cout<<ans;
  return 0;
}