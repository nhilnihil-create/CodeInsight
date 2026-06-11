#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int x;
  cin >> x;
  if(x%200==0) cout << (2000-x)/200 << endl;
  else cout << (2000-x)/200+1 << endl;
  return 0;
}
