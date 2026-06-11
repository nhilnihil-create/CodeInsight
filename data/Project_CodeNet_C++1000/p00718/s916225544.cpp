#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

int n;
string s[2];
int num[2];
map<char,int> mp;
map<int,char> imp;

int func(string s) {
  int n = s.size();
  int i = 0;
  int res = 0;
  while (i < n) {
    if (isdigit(s[i])) {
      int d = s[i]-'0';
      i++;
      res += d*mp[s[i]];
    } else {
      res += mp[s[i]];
    }
    i++;
  }
  return res;
}

string inv_func(int x) {
  string res;
  int k = 1000;
  while (x > 0) {
    int d = x/k;
    if (d != 0) {
      if (d == 1) {
        res += string(1,imp[k]);
      } else {
        res += string(1,char(d+'0'))+string(1,imp[k]);
      }
    }
    x -= d*k;
    k /= 10;
  }
  return res;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  mp['m'] = 1000;
  mp['c'] = 100;
  mp['x'] = 10;
  mp['i'] = 1;
  imp[1000] = 'm';
  imp[100] = 'c';
  imp[10] = 'x';
  imp[1] = 'i';
  cin >> n;
  REP(i,n) {
    REP(j,2) cin >> s[j], num[j] = func(s[j]);
    string ans = inv_func(num[0]+num[1]);
    cout << ans << endl;
  }

  return 0;
}
