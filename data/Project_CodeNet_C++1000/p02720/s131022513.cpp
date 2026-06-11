#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
vector<ll> ans;

void dfs(vector<ll> &A,int keta, ll now) {
  if (keta == 10)
  {
    A.push_back(now);
    return;
  }

  A.push_back(now);
  for (int i = -1; i <= 1; i++)
  {
    if((now % 10 == 0 && i == -1) || (now % 10 == 9 && i == 1)) continue;
    dfs(A, keta + 1, now * 10 + now % 10 + i);
  }
  
  
}

int main() {
  int K;
  cin >> K;
  
  for (int i = 1; i <= 9; i++)
  {
    dfs(ans, 1, i);
  }
  sort(ans.begin(), ans.end());
  cout << ans[K - 1] <<endl;
  return 0;
}
