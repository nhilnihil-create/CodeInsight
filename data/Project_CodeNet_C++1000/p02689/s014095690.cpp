#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int,int>> h(n+1,pair<int,int>(0, 0));//index=展望台i,first=展望台の標高,second=良い(0)良くない(-1)
  for(int i = 1; i <= n; i++) cin >> h[i].first;
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if(h[a].first == h[b].first) h[a].second = h[b].second = -1;
    else if(h[a].first > h[b].first) h[b].second = -1;
    else h[a].second = -1;
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(h[i].second == 0) cnt++;
  }
  cout << cnt;
}