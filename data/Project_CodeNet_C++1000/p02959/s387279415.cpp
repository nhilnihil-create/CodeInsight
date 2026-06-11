#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  vector<int> b(n);
  rep(i, n+1) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll total = 0;
  rep(i, n) {
    if(b[i]>=a[i]) total += a[i];
    else total += b[i];
    int temp = b[i];
    b[i] = max(b[i]-a[i], 0);
    a[i] = max(a[i]-temp, 0);

    if(b[i]>=a[i+1]) {
      total += a[i+1];
    } else {
      total += b[i];
    }
    temp = b[i];
    b[i] = max(b[i]-a[i+1], 0);
    a[i+1] = max(a[i+1]-temp, 0);
  }
  cout << total << endl;
  return 0;
}