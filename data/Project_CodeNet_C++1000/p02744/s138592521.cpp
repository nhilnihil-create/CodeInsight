#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int n;

void dfs(string s, int i, int k)
{
  if (i == n) {
    cout << s << endl;
    return;
  }
  int num = s[i-1] - 'a';
  k = max(k, num+1);
  for (int j=0; j<k+1; j++) {
    dfs(s, i+1, k);
    s[i]++;
  }
}

int main()
{
  cin >> n;
  string s = "";
  rep(i, n) s.push_back('a');
  dfs(s, 1, 1);

  return 0;
}
