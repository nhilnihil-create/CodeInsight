#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  int dist[n+1];
  for (int i=0; i<n; i++)
    dist[i] = INT_MAX;
  dist[n] = 0;
  int MostLeft[n+1];
  MostLeft[0] = n;
  int next = n-1;
  int left = n;
  int cnt = 0;
  while(true) {
    cnt++;
    int newLeft = left;
    while(next >= left - m && next >= 0) {
      if(s[next] == '0') {
        dist[next] = cnt;
        newLeft = next;
      }
      next--;
    }
    if(newLeft == left) {
      cout << -1 << endl;
      return 0;
    }
    left = newLeft;
    MostLeft[cnt] = left;
    if(next < 0) break;
  }
  cnt = dist[0];
  vector<int> ans;
  int now = 0;
  while(cnt >= 1) {
      cnt--;
      ans.push_back(MostLeft[cnt] - now);
      now = MostLeft[cnt];
  }
  for(int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
  cout << endl;
  return 0;
}
