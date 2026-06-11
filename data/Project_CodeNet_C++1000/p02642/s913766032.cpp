#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> fact[N + 1];
int freq[N + 1];
int main() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j * i <= N; j++)
      fact[i * j].push_back(i);
  int n, ans = 0;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    freq[v[i]]++;
  }
  for (int i = 0; i < n; i++) {
    bool absent = true;
    freq[v[i]]--;
    for (int f : fact[v[i]])
      if (freq[f])
        absent = false;
    ans += absent;
    freq[v[i]]++;
  }
  cout << ans;
  return 0;
}