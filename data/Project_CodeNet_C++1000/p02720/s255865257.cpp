#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  ll k;
  cin >> k;

  queue<ll> que;

  for (int i = 1; i < 10; i++) {
    que.push(i);
  }

  if (1 <= k && 9 >= k) {
    cout << k << endl;
    return 0;
  }
  int count = 0;

  while (1) {
    ll temp = que.front();
    count++;
    if (count == k) {
      cout << temp << endl;
      return 0;
    }
    que.pop();

    int mod = temp % 10;
    if (mod != 0) que.push(temp * 10 + mod - 1);
    que.push(temp * 10 + mod);
    if (mod != 9) que.push(temp * 10 + mod + 1);
  }
}