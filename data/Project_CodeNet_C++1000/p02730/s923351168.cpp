#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

bool is_palindrome(string s)
{
  string q(s.rbegin(), s.rend());
  if (q==s)
    return true;
  else
    return false;
}

int main()
{
  IOS;
  string s;
  cin >> s;
  int n=s.length();
  if (is_palindrome(s) && is_palindrome(s.substr(0, (n - 1) / 2)) && is_palindrome(s.substr((n + 1) / 2)))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
