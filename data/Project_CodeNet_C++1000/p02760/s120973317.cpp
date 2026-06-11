#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<int>> sheet(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>sheet.at(i).at(j);
    }
  }
  int N;
  cin>>N;
  vector<int> B(N);
  for(int i=0;i<N;i++){
    cin>>B.at(i);
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int l=0;l<N;l++){
        if(B.at(l)==sheet.at(i).at(j)){
          sheet.at(i).at(j)=-1;
        }
      }
    }
  }
  int a=0;
  for(int i=0;i<3;i++){
    if(sheet.at(i).at(0)==-1 &&sheet.at(i).at(1)==-1 && sheet.at(i).at(2)==-1){
      a=1;
    }
  }  
  for(int i=0;i<3;i++){
    if(sheet.at(0).at(i)==-1 &&sheet.at(1).at(i)==-1 && sheet.at(2).at(i)==-1){
      a=1;
    }    
  }
  if(sheet.at(0).at(0)==-1 && sheet.at(1).at(1)==-1 && sheet.at(2).at(2)==-1){
    a=1;
  }  
  if(sheet.at(0).at(2)==-1 && sheet.at(1).at(1)==-1 && sheet.at(2).at(0)==-1){
  a=1;
  }  
  if(a==1){
  cout<<"Yes"<<endl;
  }
  else{
  cout<<"No"<<endl;
  }  
}