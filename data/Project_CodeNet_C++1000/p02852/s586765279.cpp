#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;  // 9..
const ll INF = 1e9+7;

ll n, m;
string s;
vector<ll> ans;

int main() {
  cin >> n >> m >> s;

  for (ll i = n; i > 0; ) {
    ll nxt = max(i-m, 0LL);
    while (nxt < i) {
      if (s[nxt] == '0') {
        ans.push_back(i-nxt);
        break;
      }
      nxt++;
    }
    if (nxt == i) {
      cout << -1 << endl;
      return 0;
    }
    i = nxt;
  }
  
  for (auto it = ans.rbegin(); it < ans.rend(); it++) {
    cout << *it << " ";
  }
  return 0;
}