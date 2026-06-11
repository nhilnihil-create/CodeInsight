#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define LOOP(i, a, n) for (int i = (int)a; i < (int)n; ++i)
#define REP(i, n) LOOP(i, 0, n)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359

int prime(int l, int r) {
  int ret = 0;

  for (int i = l+1; i <= r; i++) {
    // i????´???°???
    bool flag = true;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }
    if(flag) {
      ret++;
    }
  }

  return ret;
}

int main(void) {
  vector<int> ans;

  while(true) {
    int n;
    cin >> n;
    if(n == 0) break;

    ans.push_back(prime(n, 2*n));
  }

  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}