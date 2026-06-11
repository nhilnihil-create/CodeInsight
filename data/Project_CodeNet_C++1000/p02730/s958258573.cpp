#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

bool is_palindrome(string s)
{
  for (size_t i = 0; i < s.size() / 2; ++i)
  {
    if (s.at(i) != s.at(s.size() - 1 - i))
      return false;
  }
  return true;
}

int main() {
  string S;
  cin >> S;

  size_t n = S.size();
  size_t m = (n - 1) / 2;
  string s = S.substr(0, m);
  string t = S.substr((n + 3) / 2 - 1, m);
  if (is_palindrome(S) && is_palindrome(s) && is_palindrome(t))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    
  return 0;
}
