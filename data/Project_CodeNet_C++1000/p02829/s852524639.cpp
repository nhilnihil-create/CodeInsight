#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int a, b;
  cin >> a >> b;
  if(a+b == 3) cout << 3 << endl;
  else if(a+b == 5) cout << 1 << endl;
  else if(a+b == 4) cout << 2 << endl;
  return 0;
}