#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N+1);
  vector<int> B(N);
  for(int i = 0;i <= N;i++) cin >> A.at(i);
  for(int i = 0;i < N;i++) cin >> B.at(i);
  
  long long int ans = 0;
  for(int i = 0;i < N;i++){
    if(A.at(i) >= B.at(i)){
      ans += B.at(i);
      B.at(i) = 0;
    }else{
      ans += A.at(i);
      B.at(i) -= A.at(i);
    }
    if(A.at(i+1) >= B.at(i)){
      ans += B.at(i);
      A.at(i+1) -= B.at(i);
    }else{
      ans += A.at(i+1);
      A.at(i+1) = 0;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}