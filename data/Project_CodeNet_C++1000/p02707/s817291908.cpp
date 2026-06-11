#include<iostream>
using namespace std;


int main(void){
  int N;
  int A[200001];
  cin >> N;
  for (int i=2; i<=N; i++){
    cin >> A[i];
  }
  
  int ans[200001];
  for (int j=2; j<=N; j++){
    ans[A[j]]++;
  }
    
  
  for (int i=1; i<=N; i++){
    cout << ans[i] << endl;
  }
  
  return 0;
}