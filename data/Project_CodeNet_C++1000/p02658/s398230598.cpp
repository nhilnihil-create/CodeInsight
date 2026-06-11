#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long int answer;
  bool ans;
  ans = false;
  answer =1;
  cin >> N;
  vector<long long int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(A[i] == 0){
      answer = 0;
    }
  }
 
  for(int i = 0; i <N; i++){
    if(answer != 0 && 
       A[i] <= 1000000000000000000/answer){
    answer *= A[i];
    }
    else{
      ans = true;
    }
    
  }
 
  if(answer == 0){
    cout << 0 << endl;
  }
  else if(ans){
    cout << -1 << endl;
  }
  else{
    cout << answer << endl;
  }
  
 	
  
}
