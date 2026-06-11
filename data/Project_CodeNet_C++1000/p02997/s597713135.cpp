#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;

int main() {
  int n, k;
  cin >> n >> k;
  int mx = (n-1)*(n-2)/2;
  if (mx < k) {
    puts("-1");
    return 0;
  }
  vector<pair<int, int> > ans;
  for(int i = 0; i < n-1; i++) {
    ans.push_back({i+1,n});
  }
  int add = mx-k;
  vector<pair<int, int> > edge;
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < i; j++) {
      edge.push_back({i+1,j+1});
    }
  }
  for(int i = 0; i < add; i++) {
    ans.push_back(edge[i]);
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}