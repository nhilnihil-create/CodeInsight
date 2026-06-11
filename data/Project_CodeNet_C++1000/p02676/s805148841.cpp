#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  if(s.size() <= k) {
    cout << s << endl;
    return 0;
  }
  else {
    // int dif = s.size() - k;
    cout << s.erase(k) + "..." << endl;
    return 0;
  }
}