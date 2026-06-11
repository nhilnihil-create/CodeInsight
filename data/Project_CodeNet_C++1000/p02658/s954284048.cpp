#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int   N;
  string S;
  cin >> N;
  vector<long long int> A(N);
  for(long long int i = 0; i < N; i++) cin >> A[i];
  
  for(long long int i = 0; i < N; i++){
    if(A[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  
  long long int prod = 1;
  for(long long int i = 0; i < N; i++){
    if(A[i] <= 1000000000000000000 / prod) prod *= A[i];
    else {
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << prod << endl;
  
}
