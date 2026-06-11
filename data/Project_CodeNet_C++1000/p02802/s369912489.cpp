#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){

  int N,M;
  cin>>N>>M;
  vector<bool>check(N,0);
  vector<int>p(M);
  vector<string>S(M);
  vector<int>pena(N,0);
  for(int i=0;i<=M-1;i++){
  
    cin>>p[i]>>S[i];
  }
  int ac=0;
  int penanum=0;
  for(int i=0;i<=M-1;i++){
  
    if(S[i]=="AC"){
    
      if(check[p[i]-1]==0){
      
        check[p[i]-1]=1;
        ac++;
      }
    }
    if(S[i]=="WA"){
    
      if(check[p[i]-1]==0){
      
        pena[p[i]-1]++;
      }
    }
  }
  for(int i=0;i<=N-1;i++){
  
    if(check[i]==1){
    
      penanum+=pena[i];
    }
  }
  cout<<ac<<" "<<penanum;
  return 0;
}