#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y;
  int count = 0;
  cin >> X >> Y;
  for (int i = 0; i <= X; i++)
  {
    for (int j = 0; j <= X; j++)
    {
      if (i * 4 + j * 2 == Y && i + j == X)
      {
        count++;
        cout << "Yes" << endl;
      }
    }
  }
  if (count == 0)
  {
    cout << "No" << endl;
  }
}