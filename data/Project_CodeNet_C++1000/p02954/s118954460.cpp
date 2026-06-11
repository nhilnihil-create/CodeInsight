#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;


int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans(n);
  int r = 0, l = 0;
  int c = 0;
  rep(i, n) {
    if (s[i] == 'R') {
      if (l != 0) {
        ans[c] += (r+1)/2 + l/2;
        ans[c+1] += (l+1)/2 + r/2;
        r = 1; l = 0;
      } 
      else r++;
    }
    else {
      if (l == 0) c = i-1;
      l++;
    }
  }
  ans[c] += (r+1)/2 + l/2;
  ans[c+1] += (l+1)/2 + r/2;
  rep(i, n) cout << ans[i] << " ";
  cout << endl;
}

