#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,M,K;
  long long zikan=0;
  long long count1=0;
  long long count2=0;
  cin >>N>>M>>K;
  
  bool seigo1=false;
  bool seigo2=false;
  
  vector<long long>AA(300000);
  vector<long long>BB(300000);
  
  for(long long i=0;i<N;i++){
    cin >>AA.at(i);
    if(zikan+AA.at(i)<=K&&seigo1==false){
      zikan += AA.at(i);
      count1++;
    }
    else{
      seigo1=true;
    }
  }
  

  for(long long j=0;j<M;j++){
    cin >>BB.at(j);
    if(zikan+BB.at(j)<=K&&seigo2==false){
      zikan += BB.at(j);
      count2++;
    }
    else{
      seigo2=true;
    }
  }
  
  
  long long total=count1+count2;
  
  long long kotei=count1;
  
  for(long long k=0;k<kotei;k++){
    count1--;
    zikan -=AA.at(count1);
    
    while(1){
      if(count2==M){
        break;
      }
      if(zikan+BB.at(count2)<=K){
        zikan += BB.at(count2);
        count2++;
      }
      else{
        break;
      }
    }
    
    if(count1+count2>total){
      total = count1+count2;
    }
  }
  cout <<total;
}
  
