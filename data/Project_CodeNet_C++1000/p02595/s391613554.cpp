#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int counter = 0;
  int N, D;
  cin >> N >> D;
  vector<int> x;
  vector<int> y;
  int temp;
  for (int i = 0; i < N; ++i)
  {
    cin >> temp;
    x.push_back(temp);
    cin >> temp;
    y.push_back(temp);
  }
  for (int i = 0; i < N; ++i)
  {
    if (sqrt(pow(x[i], 2) + pow(y[i], 2)) <= D)
      counter++;
  }

  cout << counter << endl;

  return 0;
}