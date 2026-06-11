#include <iostream>
#include <string>
using namespace std;

int main(){
  string s, t, u;
  int a, b;
  cin >> s >> t;
  cin >> a >> b;
  cin >> u;
  if (s == u) a--;
  if (t == u) b--;
  cout << a << ' ' << b << endl;
  
  return 0;
}