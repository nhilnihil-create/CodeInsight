#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int a, b;
  cin >> a >> b;
  if(b==1) {
    cout << 0 << endl;
    return 0;
  }
  int t = a;
  int ans = 1;
  while(t<b) {
    t+=a;
    t--;
    ans++;
  }
  cout << ans << endl;
  return 0;
}