#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main()
{
  string s;
  cin >> s;
  int len = s.size();
  if (s.at(len - 1) == 's')
  {
    cout << s << "es" << endl;
  }
  else
  {
    cout << s << 's' << endl;
  }
}
