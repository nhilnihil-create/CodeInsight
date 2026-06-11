#include <iostream>

using namespace std;

int main() {

  long long n, ans = 1e18;
  cin >> n;
  for(long long i = 1;i * i <= n;i++){
    if(n % i == 0){
      ans = min(ans, i + n / i);
    }
  }
  cout << ans - 2;
  return 0;
}
