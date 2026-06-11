#include <iostream>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  
  int A[1010];
  int sum = 0;
  for(int i = 0; i < N; ++i)
  {
    cin >> A[i];
    sum += A[i];
  }
  
  int m = 0;
  for(int i = 0; i < N; ++i)
  {
    if(A[i] * 4 * M >= sum)
    {
      m++;
    }
  }
  
  if(m >= M)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}