#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, m, ans = 0, a;
  cin >> n >> m;
  for(int i = 1;i <= m;i++){
    cin >> a;
    ans += a;
  }
  if(n < ans){
    cout << -1;
  }else{cout << n - ans;}
  return 0;
}
