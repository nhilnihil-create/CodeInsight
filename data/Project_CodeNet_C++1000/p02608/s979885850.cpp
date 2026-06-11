#include<bits/stdc++.h>
using namespace std;
    
int func(int N){
  int sum=0;
  for(int i=1;i<101;i++){
    for(int j=i;j<101;j++){
      for(int k=j;k<101;k++){
        if(N==i*i+j*j+k*k+i*j+j*k+k*i){
          if(i==j && j==k){
            sum+=1;
          }
          else if(i!=j && j!=k && k!=i){
            sum+=6;
          }
          else{
            sum+=3;
          }
        }
      }
    }
  }
  return sum;
}
           
int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    cout << func(i+1) << endl;
  }
}