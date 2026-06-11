#include <iostream>
#include <vector>

using namespace std;
typedef long long llong;

#define MAX 200001
const llong mod = 1000000000 + 7;

llong comb(int n)
{
  return (llong)n * (n - 1) / 2;
}

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> cnt(N + 1);
  llong total = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    cnt[A[i]]++;
  }

  for (int i = 0; i < N; i++)
  {
    total += comb(cnt[i + 1]);
  }

  for (int i = 0; i < N; i++)
  {
    int j = cnt[A[i]];
    cout << total - (comb(j) - comb(j - 1)) << endl;
  }

  return 0;
}