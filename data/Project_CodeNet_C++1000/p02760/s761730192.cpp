#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<bool>> ok(3,vector<bool>(3,false));
  vector<vector<int>> c(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>c[i][j];
    }
  }
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int s;
    cin>>s;
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
      if(s==c[j][k]){
      ok[j][k]=true;
      }
      }
    }
  }
  for(int i=0;i<3;i++){
    int count=0;
    for(int j=0;j<3;j++){
      if(ok[i][j]){
        count++;
      }
      else{
        count=0;
      }
    }
    if(count==3){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  for(int i=0;i<3;i++){
    int count=0;
    for(int j=0;j<3;j++){
      if(ok[j][i]){
        count++;
      }
      else{
        count=0;
      }
    }
    if(count==3){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  int count=0;
  for(int i=0;i<3;i++){
      if(ok[i][i]){
        count++;
      }
      else{
        count=0;
      }
    if(count==3){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  count=0;
  for(int i=2;i>=0;i--){  
    if(ok[i][2-i]){
        count++;
      }
      else{
        count=0;
      }
    if(count==3){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}

  