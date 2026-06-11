#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  vector<int> plus, minus;
  rep(i, n)
  {
    if(a[i] >= 0) plus.emplace_back(a[i]);
    else minus.emplace_back(a[i]);
  }
  sort(plus.begin(), plus.end(), greater<int>());
  sort(minus.begin(), minus.end());
  
  if(minus.empty()) minus.emplace_back(plus.back()), plus.pop_back();
  if(plus.empty()) plus.emplace_back(minus.back()), minus.pop_back();
  
  int cur = minus[0];
  vector<P> sousa;
  
  for(int i = 0; i < (int)(plus.size() - 1); i++)
  {
    sousa.emplace_back(P(cur, plus[i]));
    cur = cur - plus[i];
  }
  sousa.emplace_back(P(plus.back(), cur));
  cur = plus.back() - cur;
  
  for(int i = 1; i < minus.size(); i++)
  {
    sousa.emplace_back(P(cur, minus[i]));
    cur = cur - minus[i];
  }
  
  cout << cur << endl;
  for(auto x : sousa) cout << x.first << " " << x.second << "\n";
  
  return 0;
}