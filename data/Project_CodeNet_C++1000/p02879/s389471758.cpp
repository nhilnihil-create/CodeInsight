#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int a, b;
  cin >> a >> b;
  if(a >= 10 || b >= 10) cout << -1 << endl;
  else cout << a*b << endl;
  return 0;
}