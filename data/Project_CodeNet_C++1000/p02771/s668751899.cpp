#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b && b == c && c == a || (a != b && b != c && c != a)) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}