#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int main() {
  string s;
  cin >> s;
  int n = s.size() + 1;
  vector<int> v(n, 0);
  for(int i = 0;i < n-1;i++) if(s[i] == '<') v[i+1] = v[i] + 1;
  for(int i = n-2;i > - 1;i--) if(s[i] == '>') v[i] = max(v[i], v[i+1]+1);
  cout << accumulate(all(v), 0LL) << endl;
}