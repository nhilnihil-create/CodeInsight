// g++ .cpp && ./a.out
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;
const int inf = 1000000007;

int main() {
  int n;
  string s;
  cin >> n >> s;
  ll cnt = 0;
  vector<ll> cntR(n);
  vector<ll> cntB(n);
  vector<ll> cntG(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[j] == 'R') cntR[i]++;
      if (s[j] == 'B') cntB[i]++;
      if (s[j] == 'G') cntG[i]++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      {
        if (s[i] == 'R' && s[j] == 'B') {
          cnt += cntG[j];
          if (s[2 * (j - i) + i] == 'G' && 2 * (j - i) + i < n) cnt--;
        }
        if (s[i] == 'R' && s[j] == 'G') {
          cnt += cntB[j];
          if (s[2 * (j - i) + i] == 'B' && 2 * (j - i) + i < n) cnt--;
        }
        if (s[i] == 'B' && s[j] == 'R') {
          cnt += cntG[j];
          if (s[2 * (j - i) + i] == 'G' && 2 * (j - i) + i < n) cnt--;
        }
        if (s[i] == 'B' && s[j] == 'G') {
          cnt += cntR[j];
          if (s[2 * (j - i) + i] == 'R' && 2 * (j - i) + i < n) cnt--;
        }
        if (s[i] == 'G' && s[j] == 'B') {
          cnt += cntR[j];
          if (s[2 * (j - i) + i] == 'R' && 2 * (j - i) + i < n) cnt--;
        }
        if (s[i] == 'G' && s[j] == 'R') {
          cnt += cntB[j];
          if (s[2 * (j - i) + i] == 'B' && 2 * (j - i) + i < n) cnt--;
        }
      }
    }
  }
  cout << cnt << endl;
}
