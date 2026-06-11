#include<bits/stdc++.h>
using namespace std;
int main(){
int H,W;
  cin>>H>>W;
  vector<vector<char>>A(H,vector<char>(W));
  for(int i=0;i<H;i++){
    string s;
    cin>>s;
    for(int j=0;j<W;j++)
      A.at(i).at(j)=s.at(j);
  }vector<vector<int>>B(H,vector<int>(W,0));
  for(int i=0;i<H;i++){
    int sum=0;
    for(int j=0;j<W;j++){
      if(A.at(i).at(j)=='#'){
      sum=0; B.at(i).at(j)+=sum;
      }else{
      sum++; B.at(i).at(j)+=sum;
      }
  
  }
  }for(int j=0;j<W;j++){
    int sum=0;
    for(int i=H-1;0<=i;i--){
      if(A.at(i).at(j)=='#'){
      sum=0; B.at(i).at(j)+=sum;
      }else{
      sum++; B.at(i).at(j)+=sum;
      }
  
  }
  }for(int i=0;i<H;i++){
    int sum=0;
    for(int j=W-1;0<=j;j--){
      if(A.at(i).at(j)=='#'){
      sum=0; B.at(i).at(j)+=sum;
      }else{
      sum++; B.at(i).at(j)+=sum;
      }
  
  }
  }for(int j=0;j<W;j++){
    int sum=0;
    for(int i=0;i<H;i++){
      if(A.at(i).at(j)=='#'){
      sum=0; B.at(i).at(j)+=sum;
      }else{
      sum++; B.at(i).at(j)+=sum;
      }
  
  }
  }int ans=0;
  for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
  if(ans<B.at(i).at(j))
    ans=B.at(i).at(j);
  }
  }ans-=3;
  cout<<ans<<endl;
    return 0;
}