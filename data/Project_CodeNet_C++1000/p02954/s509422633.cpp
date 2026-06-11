#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = len(s);
  s += "R";
  vector<int> ans(n,0);
  int k = 0, p = 0;
  rep(i,0,n+1) {
    if (k == 0) {
      if (s[i] == 'L') {
        int x = i-p;
        if (x % 2 == 0) {
          ans[i-1] += x/2;
          ans[i] += x/2;
        } else {
          ans[i-1] += dup(x,2);
          ans[i] += x/2;
        }
        k ^= 1;
        p = i;
      } else continue;
    } else {
      if (s[i] == 'R') {
        int x = i-p;
        if (x % 2 == 0) {
          ans[p-1] += x/2;
          ans[p] += x/2;
        } else {
          ans[p-1] += x/2;
          ans[p] += dup(x,2);
        }
        k ^= 1;
        p = i;
      } else continue;
    }
  }
  rep(i,0,n-1) {
    cout << ans[i] << " ";
  }
  cout << ans[n-1] << endl;
  return 0;
}
