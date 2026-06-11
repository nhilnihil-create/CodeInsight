#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string input;
  cin >> input;
  if(input.at(2)==input.at(3) && input.at(4)==input.at(5)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
