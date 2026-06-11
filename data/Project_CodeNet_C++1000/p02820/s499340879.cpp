#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, R, S, P, ans = 0;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  vector<char> A(N);
  map<char, char> mp = {{'r', 'p'}, {'s', 'r'}, {'p', 's'}};
  map<char, int> score = {{'r', R}, {'p', P}, {'s', S}};
  for (int i = 0; i < N; i++)
  {
    if (i >= K && A[i - K] == mp[T[i]])
    {
      A[i] = '?';
      continue;
    }
    A[i] = mp[T[i]];
    ans += score[A[i]];
  }
  cout << ans << endl;
}