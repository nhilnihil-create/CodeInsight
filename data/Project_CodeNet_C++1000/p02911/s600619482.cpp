#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  int K;
  int Q;
  cin>>N>>K>>Q;
  vector<int>playerdata(N);
  for(int i=0;i<=N-1;i++){
  
    playerdata[i]=K;
  }
  vector<int>gamedata(Q);
  for(int i=0;i<=Q-1;i++){
  
    cin>>gamedata[i];
  }
  for(int i=0;i<=N-1;i++){
  
    playerdata[i]-=Q;
  }
  for(int i=0;i<=Q-1;i++){
  
    playerdata[gamedata[i]-1]++;
  }
  for(int i=0;i<=N-1;i++){
  
    if(playerdata[i]<=0){
    
      cout<<"No"<<endl;
    }
    else{
    
      cout<<"Yes"<<endl;
    }
  }
  return 0;
}