#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int k;
  cin >> k;
  int i = 1;
  int a = 7 % k;
  if(a == 0) {
    cout << i << endl;
    return 0;
  }
  vector<bool>v(k);
  v[a] = true;
  while(1) {
    i++;
    int an = (10 * a + 7) % k;
    if(an == 0) {
      cout << i << endl;
      return 0;
    }
    if(v[an]) break;
    v[an] = true;
    a = an;
  }
  cout << -1 << endl;
  return 0;
}