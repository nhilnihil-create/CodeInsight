#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  int count = 0;
  cin >> N;
  for (int i = 0; i < N.size(); i++)
  {
    if (N.at(i) == '7')
    {
      count++;
    }
  }
  if (count == 0)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}