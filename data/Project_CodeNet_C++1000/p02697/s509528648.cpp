//競技プログラミング用のテンプレート
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <stack>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repr(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;
using ll = long long int;
using p = pair<int, int>;
using pl = pair<ll, ll>;
using v = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vl = vector<ll>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> t(m, {0, 0});
  if(n % 2 != 0) {
    int l = 1;
    int r = n - 1;
    for(int i = 0; i < m; i++)
    {
      t[i] = {l, r};
      l++;
      r--;
    }
  }else{
    bool flag = false;
    int l = 1;
    int r = n;
    for(int i = 0; i < m; i++)
    {
      if(!flag && r - l <= n / 2) {
        r--;
        flag = true;
      }
      t[i] = {l, r};
      l++;
      r--;
    }
  }
  for(auto e : t) {
    cout << e.first << " " << e.second << endl;
  }
}
