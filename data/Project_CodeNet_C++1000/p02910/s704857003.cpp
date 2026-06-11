#include <bits/stdc++.h> 
using namespace std;

int main() {
  string S;
  cin >> S;
  int a = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i%2 == 0 && S.at(i) == 'L')
      a++;
    if (i%2 == 1 && S.at(i) =='R')
      a++;
  }
  if (a == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
