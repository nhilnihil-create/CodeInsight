#include<iostream>
using namespace std;

int main(void){
  long long N,K;
  cin >> N >> K;
  
  long long ans=N%K;
  
  ans = min(ans, K-ans);
  cout << ans << endl;
  
  return 0;
}