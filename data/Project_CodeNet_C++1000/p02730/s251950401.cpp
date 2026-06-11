#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPalindrome(string s) {
  string sr = s;
  reverse(sr.begin(), sr.end());
  return s == sr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  string s1 = s.substr((n + 1) / 2), s2 = s.substr((n + 1) / 2);
  if (isPalindrome(s) && isPalindrome(s1) && isPalindrome(s2))
    puts("Yes");
  else
    puts("No");

  return 0;
}
