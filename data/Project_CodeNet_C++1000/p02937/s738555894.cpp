#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> ch(26);
  s += s;
  int n = s.length() ;
  rep(i, n) {
    ch[s[i] - 'a'].push_back(i + 1);
  }

  int cur = 0;
  ll ans = 0;
  rep(i, t.length()) {
    int c = t[i] - 'a';
    if (ch[c].size() == 0) {
      puts("-1");
      return 0;
    }
    cur = *upper_bound(ch[c].begin(), ch[c].end(), cur);

    if (cur >= n / 2) {
      ans += n / 2;
      cur -= n / 2;
    }
  }
  ans += cur;
  cout << ans << endl;
}