#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

int main() {
    string S;
    cin >> S;

    int prev = 0;
    vector<ll> a(S.length() + 1, 0);

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '<') {
            a[i] = 0;
            ll lcnt = 1;
            
            while (S[i + lcnt] == '<') {
                a[i + lcnt] = max(lcnt, a[i + lcnt]);
                lcnt++;
            }

            a[i + lcnt] = max(lcnt, a[i + lcnt]);
            i += lcnt - 1;
        } else {
            ll rcnt = 1;
            
            while (S[i + rcnt] == '>')
                rcnt++;

            ll cnt = 0;
            
            for (int j = i + rcnt; j > i; j--) {
                a[j] = max(cnt, a[j]);
                cnt++;
            }

            a[i] = max(a[i], cnt);
            i += rcnt - 1;
        }
    }
  
  ll ans = 0;
  for (auto e : a) {
    ans += e;
  }
  cout << ans << endl;

  return 0;
}