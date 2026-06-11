#include<iostream>
using namespace std;

int main(){
  long long A, B, N;
  cin >> A >> B >> N;
  
  long long x=min(B-1, N);
  long long ans=(A*x/B)-A*(x/B);
  
  cout << ans << endl;
  
  return 0;
}