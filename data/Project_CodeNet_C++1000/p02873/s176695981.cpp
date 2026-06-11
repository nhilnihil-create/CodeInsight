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

int main()
{
  string S;
  cin >> S;
  int N = S.size() + 1;

  vector<pair<long long, long long>> CS;
  CS.push_back(make_pair(S[0], 0));
  rep(i, N - 1)
  {
    if (CS.back().first == S[i])
      CS.back().second++;
    else
      CS.push_back(make_pair(S[i], 1));
  }
  vector<long long> number;
  number.push_back(0);
  rep(i, CS.size())
  {
    if (CS[i].first == '<')
    {
      rep(j, CS[i].second)
      {
        number.push_back(j + 1);
      }
    }
    else if (CS[i].first == '>')
    {
      number.back() = max(CS[i].second, number.back());
      rep(j, CS[i].second)
      {
        number.push_back(CS[i].second - j - 1);
      }
    }
  }
  //  printVector(number);
  long long ans = 0;
  for (long long n : number)
    ans += n;

  cout << ans << endl;
  return 0;
}