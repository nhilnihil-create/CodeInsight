#include <bits/stdc++.h>
using namespace std;
int main() {
 string a,b;
  cin >> a >> b;
  int hit = 0;
  if(a.at(0)==b.at(0)) hit++;
  if(a.at(1)==b.at(1)) hit++;
  if(a.at(2)==b.at(2)) hit++;
  cout << hit << endl;
}
