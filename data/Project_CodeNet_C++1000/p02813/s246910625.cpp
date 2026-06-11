#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>P(N);
  vector<int>Q(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>P[i];
  }
  for(int i=0;i<=N-1;i++){
  
    cin>>Q[i];
  }
  int ans=0;
  vector<int>Psort(N);
  for(int i=0;i<=N-1;i++){
  
    Psort[i]=P[i];
  }
  sort(Psort.begin(),Psort.end());
  vector<int>Qsort(N);
  Qsort=Q;
  sort(Qsort.begin(),Qsort.end());
  int countP=1;
  bool flag=0;
  bool findflag=0;
  while(findflag==0){
    flag=1;
    for(int i=0;i<=N-1;i++){
    
      if(P[i]==Psort[i]){
      }
      else {
        flag=0;
        break;
      }
    }
    if(flag==1){
      break;
    }
    else {
      countP++;
      next_permutation(Psort.begin(),Psort.end());
    }
  }
  flag=0;
  int countQ=1;
  while(findflag==0){
    
    flag=1;
    for(int i=0;i<=N-1;i++){
    
      if(Q[i]==Qsort[i]){
      }
      else {
        flag=0;
        break;
      }
    }
    if(flag==1){
      break;
    }
    else {
      countQ++;
      next_permutation(Qsort.begin(),Qsort.end());
    }
  }
  ans=countP-countQ;
  if(ans<0)ans*=-1;
  cout<<ans;
  return 0;
}