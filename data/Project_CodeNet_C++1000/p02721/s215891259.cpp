#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool ss[200000];
int l[200001];
int r[200001];

int main() {
  int n, k, c; string s;
  cin >> n >> k >> c >> s;
  rep(i, n) ss[i] = (s[i] == 'x') ? false : true;
  
  int cnt = 0, i = 0;
  l[0] = 0;
  while (i < n) {
    if (ss[i]) {
      cnt++;
      int j = 0;
      while ((i < n) && (j < c + 1)) {
        l[i+1] = cnt;
        i++; j++;
      }
      while ((i < n) && (!ss[i])) {
        l[i+1] = cnt; i++;
      }
    } else {
      l[i+1] = cnt; i++;
    }
  }
  
  cnt = k+1; i = n-1;
  r[n] = k+1;
  while (i >= 0) {
    if (ss[i]) {
      cnt--;
      int j = 0;
      while ((i >= 0) && (j < c + 1)) {
        r[i] = cnt;
        i--; j++;
      }
      while ((i >= 0) && (!ss[i])) {
        r[i] = cnt; i--;
      }
    } else {
      r[i] = cnt; i--;
    }
  }
  
  //rep(i, n+1) cout << l[i] << " "; cout << endl;
  //rep(i, n+1) cout << r[i] << " "; cout << endl;
  
  rep(i, n) {
    if (r[i+1] - l[i] == 2) cout << i + 1 << endl;
  }
  
  return 0;
}
