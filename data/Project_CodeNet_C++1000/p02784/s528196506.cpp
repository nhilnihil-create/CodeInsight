#include <iostream>
using namespace std;

int main()
{
  long long H, N, A[100100];
  cin >> H >> N;
  long long sum = 0;
  for(int i = 0; i < N; ++i)
  {
    cin >> A[i];
    sum += A[i];
  }

  if(sum >= H) cout << "Yes" << endl;
  else cout << "No" << endl;
}