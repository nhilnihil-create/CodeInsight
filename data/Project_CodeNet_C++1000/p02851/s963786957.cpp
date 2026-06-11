#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  vector<long long> S(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    S[i + 1] = S[i] + A[i];
  }

  long long ans = 0;
  map<long long, int> mp;
  for (int i = 0; i <= N; i++) {
    int left = i - K;
    if (left >= 0) {
      long long x = ((S[left] - left) % K + K) % K;
      mp[x]--;
    }
    long long X = ((S[i] - i) % K + K) % K;
    ans += mp[X]++;
  }

  cout << ans << endl;

  return 0;
}