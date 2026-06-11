#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int h, a;
  cin >> h >> a;
  int ans = h / a;
  if(h%a != 0) ans++;
  cout << ans << endl;
  return 0;
}