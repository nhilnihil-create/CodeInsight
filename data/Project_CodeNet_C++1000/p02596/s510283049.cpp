#include <iostream>
using namespace std;
int main(void){
  long long K;
  cin >> K;
  
  if(K % 2 == 0) cout << -1 << endl;
  else{
    long long ans = 1;
    long long mod = 7 % K;
    
    while(mod != 0){
      ans++;
      mod = (mod * 10 + 7) % K;
      if(ans > 1000000){
        cout << -1 << endl;
        return 0;
      }
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
