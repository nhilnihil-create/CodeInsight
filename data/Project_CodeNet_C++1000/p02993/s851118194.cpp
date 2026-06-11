#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = -1;
  for (int i = 0; i < 4; i++)
  {
    if (n == S.at(i))
    {
      cout << "Bad" << endl;
      break;
    }
    else if (i == 3 && n != S.at(i))
    {
      cout << "Good" << endl;
    }
    else
    {
      n = S.at(i);
    }
  }
}