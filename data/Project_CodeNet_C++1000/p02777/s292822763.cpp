#include <iostream>
#include <string>

using namespace std;

int main() {

  string n, m, u;
  int a, b;
  cin >> n >> m >> a >> b >> u;
  if(u == n){
    a--;
  }
  if(u == m){
    b--;
  }
  cout << a << ' '<< b;
  return 0;
}
