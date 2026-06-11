#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int cnt[10][10];

int main()
{
  int n;
  cin >> n;
  
  for(int i = 1; i <= n; i++)
  {
    string s = to_string(i);
    cnt[s[0]-'0'][s.back()-'0']++;
  }
  
  int res = 0;
  rep(i,10) rep(j,10)
  {
    res += cnt[i][j] * cnt[j][i];
  }
  cout << res << endl;
  
  
  return 0;
}