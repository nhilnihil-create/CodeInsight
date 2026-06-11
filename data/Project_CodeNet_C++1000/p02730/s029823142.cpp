#include <bits/stdc++.h>
using namespace std;



int main(){
  string S;
  cin>>S;
  int N;
  N=S.size();
  
  bool can=true;
  for(int i=0;i<(N-1)/2;i++){
    if(S.at(i)!=S.at(N-i-1)){
      can=false;
      break;
    }
  }
  for(int i=0;i<((N-1)/2)/2;i++){
    if(S.at(i)!=S.at((N-1)/2-1-i)){
      can=false;
      break;
    }
       }
  reverse(S.begin(),S.end());
  for(int i=0;i<((N-1)/2)/2;i++){
    if(S.at(i)!=S.at((N-1)/2-1-i)){
      can=false;
      break;
    }
  }

  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
    
 
}