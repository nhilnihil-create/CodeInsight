#include<iostream>
using namespace std;


int main(void){
  int N,M;
  int A[10000];
  cin >> N >> M;
  
  int sum=0;
  for (int i=0; i<M; i++){
    cin >> A[i];
    sum+=A[i];
  }
  
  if (N>=sum){
    cout << N-sum << endl;
  }
  else{
    cout << "-1" << endl;
  }
  
  return 0;
}