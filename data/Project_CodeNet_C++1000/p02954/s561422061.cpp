#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[8] = {-1,0,1,-1,1,-1,0,1};
int sj[8] = {-1,-1,-1,0,0,1,1,1};

int main() {
  string s;
  cin >> s;

  vector<int> v(s.size(),1);
  int i = 0;
  bool b = false;
  int ri , li;
  int r = 0;
  int l = 0;
  vector<int> ans(s.size(),0);
  while(true){
    if (i >= s.size()) break;
    if (b == false && s[i] == 'R') {
      i++;
      r++;
      continue;
    } else if ( b == false && s[i] == 'L'){
      ri = i - 1;
      li = i;
      i++;
      l++;
      b = true;
      continue;
    }

    if (b == true && s[i] == 'L') {
      i++;
      l++;
      continue;
    } else if ( b == true && s[i] == 'R'){
      b = false;
      i++;
    }

    ans[ri] = 1;
    ans[ri] += (r-1)/2 + l/2;
    ans[li] = 1;
    ans[li] += r/2 + (l-1)/2;
    r = 1;
    l = 0;
  }
  ans[ri] = 1;
  ans[ri] += (r-1)/2 + l/2;
  ans[li] = 1;
  ans[li] += r/2 + (l-1)/2;

  rep(i,s.size()) cout << ans[i] << endl;


  return 0;
}
