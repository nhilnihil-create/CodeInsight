#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){

  int N,D;
  cin>>N>>D;
  vector<vector<int>>X(N,vector<int>(D));
  for(int i=0;i<=N-1;i++){
  
    for(int j=0;j<=D-1;j++){
    
      cin>>X[i][j];
    }
  }
  int ansint=0;
  double ansdouble=0;
  int distance=0;
  int ans=0;
  for(int i=0;i<=N-2;i++){
  
    for(int j=i+1;j<=N-1;j++){
    
      distance=0;
      for(int k=0;k<=D-1;k++){
      
        distance+=(X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
      }
      ansdouble=sqrt((double)distance);
      ansint=(int)(ansdouble);
      if((double)(ansint)==ansdouble){
        ans++;
      }
    }
  }
  cout<<ans;
  return 0;
}