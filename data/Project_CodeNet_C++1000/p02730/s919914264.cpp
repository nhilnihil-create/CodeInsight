#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1'000'000'000;

bool is_palindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  if (s == t) return true;
  else return false;
}

int main() {
  string s,s2,s3;
  cin >> s;
  int n = s.size();
  s2 = s.substr(0, (n-1)/2);
  s3 = s.substr((n+3)/2-1, n);
  if (is_palindrome(s) && is_palindrome(s2) && is_palindrome(s3)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
