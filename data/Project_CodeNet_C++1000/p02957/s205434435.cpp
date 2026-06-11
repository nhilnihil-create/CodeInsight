#include <iostream>
#include <vector>
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int x = a + b;
  if (x % 2 == 0) cout << x/2 << endl;
  else cout << "IMPOSSIBLE" << endl;
  
  return 0;
}