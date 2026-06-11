#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
 
 
int main(){
  int H, N ;
  cin >> H >> N ;
  int A[N] ;
  int B[N] ;
  for(int i=0;i<N;i++){
    cin >> A[i] >> B[i] ;
  }  
  int DP[H + 1] ;
  DP[0] = 0 ;
  for(int i=1;i<(H+1);i++){
    DP[i] = INT_MAX ;
    for(int j=0;j<N;j++){
      if(i >= A[j]){
        if(DP[i] > (DP[(i-A[j])] + B[j]) ){
          DP[i] = DP[(i-A[j])] + B[j] ;
        }  
      }
      else{
        if(DP[i] > B[j] ){
          DP[i] = B[j] ;
        }
      }  
    }  
  }  
  cout << DP[H] << endl ;
  return 0 ;
}