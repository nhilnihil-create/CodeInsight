#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int n,k,r,s,p;
ll ans = 0;
void pl(char c) {
  //if (cnt == 1) {cnt = 0; return;}
  
  if (c == 'r') ans += p;
  else if (c == 's') ans += r;
  else ans += s;
  return;
} 
int main() {
  cin>>n>>k>>r>>s>>p;
  string t;
  cin >> t;
  int j = 0;
  vector<int> cnt(n,1);
  while (j < k)
  {
    for (int i = j; i < n-k; i+=k)
    {
      if (cnt[i] == 1) {
        pl(t[i]);
        if (t[i] == t[i+k]) cnt[i+k] = 0;
      }
      else {
        if (t[i] == t[i+k]) cnt[i+k] = 1;
      }
    }
    //cout << ans << endl;
    j++;
  }
  for (int i = n-k; i < n; i++)
  {
    if (cnt[i]) pl(t[i]);
  }
  
  cout << ans << endl;
  return 0;
}