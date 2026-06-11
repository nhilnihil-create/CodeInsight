#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 
  int A;
  int B;
  int M;
  cin>>A>>B>>M;
  vector<int>A1(A);
  vector<int>B1(B);
  vector<int>MX(M);
  vector<int>MY(M);
  vector<int>MC(M);
  for(int i=0;i<=A-1;i++){
  
    cin>>A1[i];
  }
  for(int i=0;i<=B-1;i++){
  
    cin>>B1[i];
  }
  for(int i=0;i<=M-1;i++){
  
    cin>>MX[i];
    cin>>MY[i];
    cin>>MC[i];
  }
  int minvalue=99999999;
  for(int i=0;i<=M-1;i++){
  
    if(minvalue>A1[MX[i]-1]+B1[MY[i]-1]-MC[i])
    minvalue=A1[MX[i]-1]+B1[MY[i]-1]-MC[i];
  }
  sort(A1.begin(),A1.end());
  sort(B1.begin(),B1.end());
  if(A1[0]+B1[0]<minvalue){
  
    minvalue=A1[0]+B1[0];
  }
  cout<<minvalue;
  return 0;
}