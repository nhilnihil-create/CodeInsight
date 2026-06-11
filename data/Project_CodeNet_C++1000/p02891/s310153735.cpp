#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  string s; cin >> s;
  lint k; cin >> k;
  lint ans = 0;


  // 全文字一緒の場合
  bool allSame = true;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) allSame = false;
  }

  if (allSame) {
    cout << s.size() * k / 2 << endl;
    return 0;
  }

  lint cnt = 0;
  char cur = '*';
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == cur) cnt++;
    else {
      ans += cnt / 2;
      cur = s[i];
      cnt = 1;
    }
  }
  ans += cnt / 2;
  cerr << ans << endl;
  ans *= k;

  if (s[0] == s[s.size() - 1]) {
    char c = s[0];
    lint a = 0;
    lint b = 0;
    for (int i = 0; s[i] == c; i++) {
      a++;
    }
    for (int i = s.size() - 1; s[i] == c; i--) {
      b++;
    }
    
    cerr << ans << " " << a << " " << b << endl;
    ans -= (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
  }

  cout << ans << endl;
  return 0;
}
