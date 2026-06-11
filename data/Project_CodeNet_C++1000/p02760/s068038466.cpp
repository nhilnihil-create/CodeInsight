#include <bits/stdc++.h>
using namespace std;
 
int main(){
  vector<vector<int>> B(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>B[i][j];
    }
  }
  int N;
  cin>>N;
  vector<int> b(N);
  for(int i=0;i<N;i++){
    cin>>b[i];
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(b[k]==B[i][j]){
          B[i][j]=0;
        }
      }
    }
  }
  if(B[0][0]==0&&B[1][0]==0&&B[2][0]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[0][1]==0&&B[1][1]==0&&B[2][1]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[0][2]==0&&B[1][2]==0&&B[2][2]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[0][0]==0&&B[1][1]==0&&B[2][2]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[0][2]==0&&B[1][1]==0&&B[2][0]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[0][0]==0&&B[0][1]==0&&B[0][2]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[1][0]==0&&B[1][1]==0&&B[1][2]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(B[2][0]==0&&B[2][1]==0&&B[2][2]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  else{
    cout<<"No"<<endl;
    return 0;
  }
}