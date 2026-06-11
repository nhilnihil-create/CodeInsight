#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int M,D;
  cin>>M>>D;
  int answer=0;
  if(D>=22){
  for(int i=2;i<=D/10;i++){
    if(i<D/10){
      for(int j=2;j<=9;j++){
        if(i*j<=M){
          answer++;
        }
      }
    }
    else if(i==D/10&&D%10>=2){
      for(int j=2;j<=D%10;j++){
        if(i*j<=M){
          answer++;
        }
      }
    }
  }
 }
  cout<<answer<<endl;
}
/*int main(){
  int N;
  cin>>N;
  int A[20],B[20],C[20];
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  for(int i=1;i<=N;i++){
    cin>>B[i];
  }
  int answer=0;
  for(int i=1;i<=N-1;i++){
   cin>>C[i]; 
  }
  for(int i=1;i<=N;i++){
    answer+=B[A[i]];
    if(i>=2&&A[i]-A[i-1]==1){
      answer+=C[A[i-1]];
    }
  }
  cout<<answer<<endl;
}*/
/*int main(){
  int N;
  cin>>N;
  cout<<N*N*N<<endl;
}*/