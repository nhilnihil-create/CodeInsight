#include <iostream>
using namespace std;

int main(){
  int K;
  cin >> K;
  long long a = 7;
  int ans = -1;
  for(int i=1; i<=K; i++){
    if(a%K==0){
      ans = i;
      break;
    }
    a = 10*a+7;
    a %= K;
  }
  cout << ans;
  return 0;
}