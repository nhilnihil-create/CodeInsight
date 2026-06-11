#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, l, ans, relens = 1e9;
  cin >> n >> l;
  ans = l * n + (n * (n-1)) / 2;
  for(int i = 1;i <= n;i++){
    if(abs(relens) > abs(l + i - 1)){
      relens = l + i - 1;
    }
  }
  cout << ans - relens;
  return 0;
}
