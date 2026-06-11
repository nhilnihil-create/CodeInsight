#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, m, k, p, a = 0;
  cin >> n >> k;
  for(int i = 1;i <= n;i++){
    cin >> m;
    if(m >= k){
      a++;
    }
  }
  cout << a;
  return 0;
}
