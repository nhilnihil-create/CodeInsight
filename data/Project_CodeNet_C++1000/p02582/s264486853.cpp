#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i <s.size(); i++) {
    if (s.at(i) == 'R')
      sum++;
  }
  if (sum == 2 && s.at(1) == 'S') 
    sum--;
  cout << sum << endl;
}
    