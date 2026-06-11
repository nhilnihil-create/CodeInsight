//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

const int N = (int) 3e5 + 10;

int h[N], w[N], cnth[N], cntw[N];
bool markh[N], markw[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> h[i] >> w[i];
    --h[i]; --w[i];
    ++cnth[h[i]];
    ++cntw[w[i]];
  }
  int mxh = *max_element(cnth, cnth + n);
  int mxw = *max_element(cntw, cntw + m);
  int cnt_mxh = 0, cnt_mxw = 0;
  for (int i = 0; i < n; i++) {
    if (cnth[i] == mxh) {
      markh[i] = true;
      ++cnt_mxh;
    }
  }
  for (int i = 0; i < m; i++) {
    if (cntw[i] == mxw) {
      markw[i] = true;
      ++cnt_mxw;
    }
  }
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    if (markh[h[i]] && markw[w[i]]) {
      ++cnt;
    } 
  }
  if ((ll) cnt_mxh * cnt_mxw > (ll) cnt) {
    cout << mxh + mxw << '\n';
    return 0;
  }
  cout << mxh + mxw - 1 << '\n';
  return 0;
}
