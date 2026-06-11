#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<int> t(1000000);

int main() {
    int k;
    cin >> k;
    int sev = 7;
    int cnt = 0;
    while (1) {
      sev %= k;
      if (t[sev]) {
        cout << -1 << endl;
        return 0;
      }
      t[sev]++;
      cnt++;
      if (sev == 0) break;
      sev = sev*10 + 7;
    }
    cout << cnt << endl;
    return 0;
}