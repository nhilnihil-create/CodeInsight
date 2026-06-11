#include<iostream>
using namespace std;

int N=100000;

long Low(long n){
  if(n%10 == 0){
    return 0;
  }
  else{
    return n*10+(n%10-1);
  }
}

long Middle(long n){
  return n*10+n%10;
}

long High(long n){
  if(n%10 == 9){
    return 0;
  }
  else{
    return n*10+(n%10+1);
  }
}
  

int main(void){
  int K;
  cin >> K;
  
  long A[100002];
  for (int i=0;i<=8;i++){
    A[i]=i+1;
  }
  int pre=0,count=9;
  
  while(1){
    if (Low(A[pre]) != 0){
      A[count]=Low(A[pre]);
      count++;
    }
    
    A[count]=Middle(A[pre]);
    count++;
    
    if (High(A[pre]) != 0){
      A[count]=High(A[pre]);
      count++;
    }
    
    pre++;
    
    if(count>=N){
      break;
    }
  }
  
  cout << A[K-1] << endl;
  
  
  return 0;
}