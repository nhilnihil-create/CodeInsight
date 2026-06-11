#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
string s;
int q;
cin >> s >> q;
  int cnt = 0;

rep(i,q) {
  int t;
  cin >> t;
  if (t == 1) {
    cnt++;
  } else {
    int f;
    char c;
    cin >> f >> c;
    if (f == 1 && cnt % 2 == 0 || f ==2 && cnt %2 == 1) {
      string k;
      k.push_back(c);
      k += s;
      s = k;
    }else {
      s.push_back(c);
    }
  }
}
if (cnt % 2 == 1) reverse(s.begin(),s.end());
cout << s << endl;

return 0;
}

