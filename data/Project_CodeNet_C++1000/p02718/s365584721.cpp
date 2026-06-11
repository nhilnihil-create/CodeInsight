#include <iostream>
using namespace std;

int main(void){
  int M,N;
  cin >> N >> M;
  
  int A[100];
  int sum=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum += A[i];
  }
  
  int count=0;
  
  for (int i=0; i<N; i++){
    if (A[i]*4*M >= sum){
      count++;
    }
  }
  
  if (count >= M){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  
  return 0;
}
