#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  map<int, int> m;
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (m.find(x) != m.end()) m[x]++;
    else m[x] = 1;
  }
  
  vector<int> v, s;
  for (auto it = m.begin(); it != m.end(); it++) {
    v.push_back(it->second);
  }
  sort(v.begin(), v.end());
  s.resize(v.size());
  for (int i = 0; i < s.size(); i++) {
    s[i] = v[i];
    if (i) s[i] += s[i - 1];
  }
  
  for (int i = 1; i <= n; i++) {
    int l = 0, r = n / i;
    while (l != r) {
      int m = (l + r + 1) / 2;
      int pos = upper_bound(v.begin(), v.end(), m) - v.begin();
      int sum = (pos ? s[pos - 1] : 0) + m * ((int)v.size() - pos);
      if (sum >= i * m) l = m;
      else r = m - 1;
    }
    printf("%d\n", l);
  }
  
  return 0;
}