#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, t;
int s_len, t_len;
vector<int> v[26];
long long ans; 

void binary_search(int i)
{
  int pos = ans % s_len;
  int l = 0, r = v[i].size(), mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (pos > v[i][mid]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  
  if (l == v[i].size()) {
    ans = (ans / s_len + 1) * s_len + v[i][0];
  } else {
    ans = (ans / s_len) * s_len + v[i][l];
  }
  ans++;
}

int main()
{
  cin >> s >> t;
  s_len = s.length();
  t_len = t.length();
  
  for (int i = 0; i < s_len; i++) {
    v[s[i]-'a'].push_back(i);
  }
  
  for (int i = 0; i < t_len; i++) {
    if (v[t[i]-'a'].empty()) {
      cout << -1 << endl;
      return 0;
    }
    binary_search(t[i]-'a');
  }
  
  cout << ans << endl;
  return 0;
}