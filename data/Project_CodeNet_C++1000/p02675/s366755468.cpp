#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  char x = n.at(n.size()-1);
  if(x == '3') cout << "bon";
  else if(x == '0' || x == '1' || x == '6' || x == '8') cout << "pon";
  else cout << "hon";
}