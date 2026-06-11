#include <bits/stdc++.h>
using namespace std;
int main() {
 string a;
  cin >> a;
  if(a.at(0)=='S') cout << "Cloudy" << endl;
  else if(a.at(0)=='R') cout << "Sunny" << endl;
  else cout << "Rainy" << endl;
}
