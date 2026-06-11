#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
    A[i]--;
  }

  vector<int> B(N);
  rep(i, N)
  {
    cin >> B[i];
  }

  vector<int> C(N - 1);
  rep(i, N - 1)
  {
    cin >> C[i];
  }

  int sum = 0;
  int before = -1;
  rep(i, N)
  {
    sum += B[A[i]];
    if (before + 1 == A[i])
    {
      sum += C[before];
    }
    before = A[i];
  }

  cout << sum << endl;

  return 0;
}
