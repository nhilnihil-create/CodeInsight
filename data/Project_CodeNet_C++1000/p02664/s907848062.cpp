#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr) / sizeof(value), (value))

template <typename T>
void FILL_(void *ptr, size_t size, T value)
{
  std::fill((T *)ptr, (T *)ptr + size, value);
}

inline int toInt(string s)
{
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x)
{
  ostringstream sout;
  sout << x;
  return sout.str();
}

int dp[200002][2];
int pre[200002][2];

int main()
{
  std::ios::sync_with_stdio(false);
  string t;
  cin >> t;
  for (int i = 0; i < t.length(); ++i)
  {
    if (t[i] == 'P')
    {
      if (dp[i][0] >= dp[i][1])
      {
        dp[i + 1][0] = dp[i][0];
        pre[i + 1][0] = 0;
      }
      else
      {
        dp[i + 1][0] = dp[i][1];
        pre[i + 1][0] = 1;
      }
    }
    else if (t[i] == 'D')
    {
      int a = dp[i][0] + 2;
      int b = dp[i][1] + 1;
      if (a >= b)
      {
        dp[i + 1][1] = a;
        pre[i + 1][1] = 0;
      }
      else
      {
        dp[i + 1][1] = b;
        pre[i + 1][1] = 1;
      }
    }
    else
    {
      int a = dp[i][0];
      int b = dp[i][1];

      if (a >= b)
      {
        dp[i + 1][0] = a;
        pre[i + 1][0] = 0;
      }
      else
      {
        dp[i + 1][0] = b;
        pre[i + 1][0] = 1;
      }

      a = dp[i][0] + 2;
      b = dp[i][1] + 1;

      if (a >= b)
      {
        dp[i + 1][1] = a;
        pre[i + 1][1] = 0;
      }
      else
      {
        dp[i + 1][1] = b;
        pre[i + 1][1] = 1;
      }
    }
  }
  int cur;
  if(dp[t.length()][0] >= dp[t.length()][1])
  {
    cur = 0;
  }else{
    cur = 1;
  }

  vector<char> res;
  string pd = "PD";
  res.push_back(pd[cur]);
  for(int i=t.length()-1; i>0; --i)
  {
    cur = pre[i+1][cur];
    res.push_back(pd[cur]);
  }

  for(int i=0;i<res.size();++i)
  {
    cout << res[res.size()-i-1];
  }
  cout << endl;
}