#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ll (long long)
#define PI (acos(-1))

int main()
{
  int N, K;
  cin >> N >> K;
  
  vector<int> d(K);
  vector<vector<int>> A(K, vector<int>(N));
  vector<int> have(N);
  int who;

  

  for (int i = 0; i < K; i++)
  {
    cin >> d[i];

    for (int j = 0; j < d[i]; j++)
    {
      cin >> who;
      have[who - 1] = 1;
    }
  }

  int num = 0;
  for (int i = 0; i < N; i++)
  {
    if (have[i] == 0)
    {
      num++;
    }
  }
  cout << num << endl;
}
