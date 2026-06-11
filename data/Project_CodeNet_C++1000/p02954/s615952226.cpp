#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  int N = S.length();
  vector<string> T;
  vector<int> r;
  int k = 0;
  int cnt = 0;
  int cntR = 0;
  S += 'R';
  for (int i = 0; i < N ; i++)
  {
    cnt++;
    if (S[i] == 'L' && S[i + 1] == 'R')
    {
      string t = "";
      t = S.substr(k, cnt);
      T.push_back(t);
      r.push_back(cntR);
      k = i + 1;
      cnt = 0;
      cntR = 0;
      continue;
    }
    if (S[i] == 'R' && S[i + 1] == 'L')
    {
      cntR = cnt;
    }
      
  }
  
  vector<int> ans(N, 0);
  int j = -1;
  for (int i = 0; i < T.size(); i++)
  {
    int l = T[i].length() - r[i];

    if (r[i] >= l)
    {
      ans[j + r[i]] = (T[i].length() + 1) / 2;
    } else
    {
      ans[j + r[i]] = T[i].length() / 2;
    }
    ans[j + r[i] + 1] = T[i].length() - ans[j + r[i]];

    if ((max(r[i], l) - 1) % 2 != 0) {
      swap(ans[j + r[i]], ans[j + r[i] + 1]);
    }
    j += T[i].length();
  }
  
  for (int i = 0; i < N; i++)
  {
    cout << ans[i];
    if (i == N - 1)
    {
      cout << endl;
    } else
    {
      cout << " ";
    }  
  }
  return 0;
}
