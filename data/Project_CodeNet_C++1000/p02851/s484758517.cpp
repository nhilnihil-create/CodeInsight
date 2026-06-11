#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> A(N), S(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    A.at(i)--;
    S.at(i + 1) = (S.at(i) + A.at(i)) % K;
  }
  map<int64_t, int64_t> mp;
  for (int i = 0; i < min(K, N + 1); i++)
  {
    mp[S.at(i)]++;
  }
  int64_t ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    ans += it->second * (it->second - 1) / 2;
  }
  for (int i = 0; i + K <= N; i++)
  {
    mp[S[i]]--;
    mp[S[i + K]]++;
    ans += mp[S[i + K]] - 1;
  }
  cout << ans << endl;
}
