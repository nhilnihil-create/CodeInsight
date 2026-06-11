#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  bool flag = true;
  cin >> n;
  if(n%2 != 0) {
    cout << "No" << endl;
    flag = false;
  }
  if (flag){
    string s;
    cin >> s;
    rep(i,0,n/2){
      if(s[i]!=s[i+n/2]){
        cout << "No" << endl;
        flag = false;
        break;
      }
    }
  }
  if(flag) cout << "Yes" << endl;
  return 0;
}