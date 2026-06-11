#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

vector<vector<int>> graph;
set<P> st;


int main(){
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  int mx = (n - 1) * (n - 2) / 2;
  if (mx < k) {
    puts("-1");
    return 0;
  }
  vector<P> ans;
  rep(i, n - 1) {
    ans.emplace_back(i + 1, n);
  }
  vector<P> edge;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      edge.emplace_back(i + 1, j + 1);
    }
  }
  int add = mx - k;
  rep(i, add) {
    ans.push_back(edge[i]);
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i].first << ' ' << ans[i].second << endl;


}