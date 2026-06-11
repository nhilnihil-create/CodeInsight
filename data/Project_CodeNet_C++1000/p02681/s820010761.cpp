#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S, T;
  cin >> S >> T;
  int j = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == T.at(i))
    {
      j += 1;
    }
  }
  if (S.size() == j)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}