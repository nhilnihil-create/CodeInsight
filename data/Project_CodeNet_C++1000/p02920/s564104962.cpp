#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  multiset<int> st;
  REP(i, 1 << n) {
    int s;
    cin >> s;
    st.insert(-s);
  }
  vector<int> cur, nxt;
  cur.push_back(*st.begin());
  st.erase(*st.begin());
  REP(i, n) {
    nxt = cur;
    REP(j, cur.size()) {
      auto it = st.upper_bound(cur[j]);
      if (it == st.end()) {
        puts("No");
        return 0;
      }
      nxt.push_back(*it);
      st.erase(st.find(*it));
    }
    cur = nxt;
  }
  puts("Yes");
  return 0;
}