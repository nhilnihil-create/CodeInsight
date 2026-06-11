#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int N, M, Q;
vector<int> a, b, c, d;
int ans;

void dfs(vector<int> &A) {
  if (A.size() == N + 1)
  {
    int temp = 0;
    for (int i = 0; i < Q; i++)
    {
      if (A[b[i]] - A[a[i]] == c[i])
      {
        temp += d[i];
      }
      
    }
    ans = max(ans, temp);
    return;
  }
  
  for (int i = A.back(); i <= M; i++)
  {
    A.push_back(i);
    dfs(A);
    A.pop_back();
  }
  
}

int main() {
  cin >> N >> M >> Q;
  a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    // --a[i]; --b[i];
  }
  
  vector<int> A;
  A.push_back(1);
  ans = 0;
  dfs(A);
  cout << ans << endl;
  return 0;
}
