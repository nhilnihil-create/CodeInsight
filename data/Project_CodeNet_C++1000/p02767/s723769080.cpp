#include <bits/stdc++.h>
using namespace std;
int effort(int q,vector<int> &adress,int &N){
int a=0;
  for(int i=0;i<N;i++){
  a+=(q-adress.at(i))*(q-adress.at(i));
  }
  return a;                     
}
int main(){
  int N;
  cin>>N;
  vector<int> adress(N);
  for(int i=0;i<N;i++){
  cin>>adress.at(i);
  }
  int ans=1000000000;
  for(int i=0;i<100;i++){  
  if(effort(i,adress,N)<ans){
  ans=effort(i,adress,N);
  }
}  
  cout<<ans<<endl;
}