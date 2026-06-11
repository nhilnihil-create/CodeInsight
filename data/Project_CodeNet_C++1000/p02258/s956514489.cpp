#include<iostream>
using namespace std;
int main(){
  int N,R[200000],h;
  int min=1000000000,max,dis=-1000000000;
  cin >>N;
  for(int t=1;t<=N;t++){
    cin >> R[t];
  }
 
  for(int t=1;t<N;t++){
    if(min>=R[t]){
      min=R[t];
      max=-1;
      for(int i=t+1;i<=N;i++) if(max<R[i]) max=R[i];
      if((max-min) >= dis) dis=max-min;
    }
      }
     
  cout <<dis<<endl;
  return 0;
}