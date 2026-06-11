#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  vector<bool> b(81, false);
  cin >> N;

  for (int i = 1; i <= 9; i++)
  {
    for (int j = i; j <= 9; j++)
    {
      b[i * j - 1] = true;
    }
  }

  if (b[N - 1])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
