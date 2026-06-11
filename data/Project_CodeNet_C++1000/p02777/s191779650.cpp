#include <bits/stdc++.h>
using namespace std;
int main() {

  int a,b;
  string t,u;
  cin >> t >> u>>a>>b;
  string c;
  cin >> c;
  if(t==c)a--;
  if(u==c)b--;
  cout << a << " " << b << endl;
}
