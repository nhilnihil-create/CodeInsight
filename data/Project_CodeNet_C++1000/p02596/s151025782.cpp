#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define mp make_pair
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K;
  cin >> K;
  set<int> s;
  int c = 7;
  int cnt = 1;
  while(1) {
    c %= K;
    if (c == 0) {
      cout << cnt << endl;
      break;
    }
    else if (s.find(c) != s.end()) {
      cout << "-1" << endl;
      break;
    }
    else {
      s.insert(c);
      cnt++;
      c = c*10+7;
    }
  }
}
