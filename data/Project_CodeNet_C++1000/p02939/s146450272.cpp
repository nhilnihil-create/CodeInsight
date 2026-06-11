#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int K1[200010]={};
  int K2[200010]={};
  
  for(int i=S.size()-1; i>=0; i--){
    if(i==S.size()-1){
      K1[i]=1;
      K2[i]=0;
    }else if(i==S.size()-2){
      K1[i]=(S[i]==S[i+1]?0:2);
      K2[i]=1;
    }else if(i==S.size()-3){
      K1[i]=1+max(S[i]==S[i+1]?0:K1[i+1],K2[i+1]);
      K2[i]=1+K1[i+2];
    }else{
      K1[i]=1+max(S[i]==S[i+1]?0:K1[i+1],K2[i+1]);
      K2[i]=1+max(K1[i+2],S.substr(i,2)==S.substr(i+2,2)?0:K2[i+2]);
    }
  }
  cout << max(K1[0],K2[0]) << endl;
}