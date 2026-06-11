#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 135, task c, 2020/08/14
//ms,
/*
*/

int main(void){
  int N;
  vector<int64_t> A, B;
  int64_t ans=0;

  //input
  cin >>N;
  //A
  for(int i=0;i<N+1;i++){
    int64_t tmp;
    cin >>tmp;
    A.push_back(tmp);
  }
  //B
  for(int i=0;i<N;i++){
    int64_t tmp;
    cin >>tmp;
    B.push_back(tmp);
  }

  for(int i=0;i<N;i++){
    if(B[i] <= A[i]){
      ans += B[i];
      A[i] -= B[i];
    }
    else if(B[i] <= A[i]+A[i+1]){
      ans += B[i];
      A[i+1] -= B[i]-A[i];
      A[i] = 0;
    }
    else {
      ans += A[i]+A[i+1];
      A[i+1] = 0;
      A[i] = 0;
    }
    //cout <<ans <<endl;
  }

  cout <<ans<<endl;

  return 0;
}
/*
*/
