#include <iostream>
#include <cmath>
using namespace std;

int pow_int(int x, int y)
{
  return (int)pow((double)x, y);
}

int main()
{
  int N, K;
  cin >> N >> K;

  int n = 1;
  while(true)
  {
    if(N < pow_int(K, n))
    {
      cout << n << endl;
      break;
    }
    n++;
  }
}