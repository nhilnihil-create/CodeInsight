#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<pair<int, int>> ans;
void push_ans(int x, int y)
{
  ans.push_back(make_pair(x, y));
}

int main()
{
  int N;
  cin >> N;
  priority_queue<int> plus, none_plus;
  rep(i, N)
  {
    int A;
    cin >> A;
    if (A > 0)
      plus.push(A);
    else
      none_plus.push(A);
  }

  int M, P;
  if (plus.size() < 2)
  {
    if (plus.size() == 0)
    {
      M = none_plus.top();
      none_plus.pop();
    }
    else
    {
      M = plus.top();
      plus.pop();
    }
    while (none_plus.size())
    {
      int m = none_plus.top();
      push_ans(M, m);
      M -= m;
      none_plus.pop();
    }
  }
  else
  {
    int P = plus.top();
    plus.pop();
    if (none_plus.size() == 0)
    {
      vector<int> temp;
      while (plus.size())
      {
        temp.push_back(plus.top());
        plus.pop();
      }
      SORT(temp);
      M = temp[0];
      rep(i, temp.size() - 1)
      {
        push_ans(M, temp[i + 1]);
        M -= temp[i + 1];
      }
      push_ans(P, M);
      M = P - M;
    }
    else
    {
      M = none_plus.top();
      none_plus.pop();
      while (plus.size())
      {
        push_ans(M, plus.top());
        M -= plus.top();
        plus.pop();
      }
      none_plus.push(M);
      M = P;
      while (none_plus.size())
      {
        push_ans(M, none_plus.top());
        M -= none_plus.top();
        none_plus.pop();
      }
    }
  }

  cout << M << endl;
  rep(i, ans.size())
  {
    cout << ans[i].first << " " << ans[i].second << endl;
  }

  return 0;
}