#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  if (S.at(0) == S.at(1) && S.at(2) == S.at(3))
    count++;
  if (S.at(0) == S.at(2) && S.at(1) == S.at(3)) 
    count++;
  if (S.at(0) == S.at(3) && S.at(1) == S.at(2))
    count++;
  if (count == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
      
}
