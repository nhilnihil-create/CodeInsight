#include<bits/stdc++.h>
using namespace std;


int main(){
  
  int i;
  string S;
  vector<int>  Num(100000), LRPos(100000);
  cin>>S;
  
  int ix=0; char sr_=S[0];
  for(int i=1; i<S.size(); i++){

    if(sr_=='R' && S[i]=='L'){
      LRPos[ix]=i-1; ix++;
      Num[i-1]++; Num[i]++;
    }
    sr_=S[i];
  }
  
  ix=0;
  for(i=0; i<S.size(); i++){
    
    if(LRPos[ix]==i){
      i++; ix++;
      continue;
    }
    
    if(S[i]=='R'){
      Num[LRPos[ix]+(LRPos[ix]-i)%2]++;
    }else{
      Num[LRPos[ix-1]+(i-LRPos[ix-1])%2]++;
    }
  }
  for(i=0; i<S.size(); i++){
    cout<<Num[i]<<" ";
  }
  return 0;
}