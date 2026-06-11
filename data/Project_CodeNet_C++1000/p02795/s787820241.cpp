#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,N,K;
  cin>>H>>W>>N;
  K=max(H,W);
  if(N%K==0){
      cout<<N/K<<endl;
      return 0;
  }
  else{
    cout<<N/K+1<<endl;
    return 0;
  }
   
  return 0;
}


   
    
  
 