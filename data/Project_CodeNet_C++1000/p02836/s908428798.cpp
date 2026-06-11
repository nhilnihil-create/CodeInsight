#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string s;
  cin >> s;

  int n = s.size();
  int flag = 0;

  string s2 = s;
  rep(i,n){
    s2.at(i) = s.at(n - i - 1);
  }

  rep(i,n){
    if (s.at(i) != s2.at(i))
      flag++;
  }

  cout << flag/2;
}
