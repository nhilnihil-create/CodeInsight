#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  vector<int> A;
  cin >> N;
  
  for(long long i = 0; i < N; ++i)
  {
    int a;
    cin >> a;
    A.push_back(a);
  }
  
  int max = A[0];
  long long step = 0;
  for(long long i = 1; i < N; i++)
  {
    if(max > A[i])
    {
      step += max - A[i];
    }
    else
    {
      max = A[i];
    }
  }
  
  cout << step << endl;
  
  return 0;
}