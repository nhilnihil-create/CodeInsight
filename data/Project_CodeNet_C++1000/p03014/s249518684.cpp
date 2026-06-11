#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> vec(h, "");
  rep(i, h) cin >> vec.at(i);
  vector<vector<pair<int, int>>> mp(h, vector<pair<int, int>>(w, make_pair(0, 0)));
  rep(i, h) {
    int j = 0;
    while(j < w) {
      if (vec.at(i).at(j) == '#') {
        j++;
        continue;
      }

      int k = j;
      int cnt = 0;
      while(k < w && vec.at(i).at(k) == '.') {
        cnt++;
        k++;
      }
      int tmp = k;
      k--;
      while(k >= j) {
        mp.at(i).at(k).first = cnt;
        k--;
      }
      j = tmp;
    }
  }
  rep(i, w) {
    int j = 0;
    while(j < h) {
      if (vec.at(j).at(i) == '#') {
        j++;
        continue;
      }
      int k = j;
      int cnt = 0;
      while(k < h && vec.at(k).at(i) == '.') {
        cnt++;
        k++;
      }
      int tmp = k;
      k--;
      while(k >= j) {
        mp.at(k).at(i).second = cnt;
        k--;
      }
      j = tmp;
    }
  }
  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      ans = max(ans, mp.at(i).at(j).first + mp.at(i).at(j).second - 1);
    }
  }
  cout << ans << endl;
  return 0;
}