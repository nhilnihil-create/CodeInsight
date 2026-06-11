#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;
  string s;
  cin >> a;
  cin >> s;

  if(a>=3200) {
    cout << s << endl;
  }

  else if (a<3200) {
    cout << "red" << endl;
  }
  return 0;
}
