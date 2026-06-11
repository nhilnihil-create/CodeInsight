#include <bits/stdc++.h>
using namespace std;
int N, M, Q, ans = 0;
vector<int> A(55), B(55), C(55), D(55);
vector<vector<int>> S;

void calc(vector<int> &v)
{
  int score = 0;
  for (int i = 0; i < Q; i++)
  {
    if (v.at(B.at(i)) - v.at(A.at(i)) == C.at(i))
    {
      score += D.at(i);
    }
  }
  ans = max(ans, score);
}

void dfs(int n, string s)
{
  if (s.size() == N)
  {
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
      v.push_back((int)(s.at(i) - '0'));
    }
    return calc(v);
  }
  for (int i = n; i <= M; i++)
  {
    char c = '0' + i;
    dfs(i, s + c);
  }
}

int main()
{
  cin >> N >> M >> Q;
  for (int i = 0; i < Q; i++)
  {
    cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);
    A.at(i)--, B.at(i)--;
  }
  dfs(1, "");
  cout << ans << endl;
}
