#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string s;
int main()
{
  
  cin >> s;
  string rs = "";
  rep(i, s.size()) {
    rs += s[i];
  }
  string a = "";
  string ra = "";
  string b = "";
  string rb = "";
  rep(i, (s.size() -1)/2) {
    a += s[i];
    ra += s[i];
  }
  for(int i = (s.size() + 3)/2 - 1; i < s.size(); i++) {
    b += s[i];
    rb += s[i];
  }
  reverse(ra.begin(), ra.end());
  reverse(rb.begin(), rb.end());
  reverse(rs.begin(), rs.end());
  if (a == ra && b == rb && s == rs) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  
  return 0;
}