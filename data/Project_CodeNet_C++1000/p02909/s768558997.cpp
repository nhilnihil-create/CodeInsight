#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s;
  cin >> s;
  if (s[0] == 'S') {
    cout << "Cloudy" << endl;
  } else if (s[0] == 'C') {
    cout << "Rainy" << endl;
  } else if (s[0] == 'R') {
    cout << "Sunny" << endl;
  }
  return 0;
}