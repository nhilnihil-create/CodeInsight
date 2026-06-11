#include <iostream>
using namespace std;

int main()
{
  int N, X[110];
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> X[i];

  // 考え得る最大の消費量(100^2x100人分)を初期値にしておく
  int min = 1000000;
  for(int p = 1; p <= 100; ++p)
  {
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
      sum += (X[i]-p) * (X[i]-p);
    }
    if(min > sum)
    {
      min = sum;
    }
  }
  
  cout << min << endl;
}