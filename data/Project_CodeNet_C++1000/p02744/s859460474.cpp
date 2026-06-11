#include <bits/stdc++.h>
using namespace std;
int64_t N;

void dfs(string s, char maxc)
{
  if (s.size() == N)
  {
    cout << s << endl;
    return;
  }
  char last = (s[s.size() - 1] == maxc ? maxc + 1 : maxc);
  for (char c = 'a'; c <= last; c++)
  {
    string next_s = s + c;
    dfs(next_s, last);
  }
}

int main()
{
  cin >> N;
  string S = "a";
  dfs(S, 'a');
}
