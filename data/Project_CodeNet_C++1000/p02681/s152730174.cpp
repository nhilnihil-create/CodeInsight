#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  string s, t;
  cin >> s >> t;
  string u = t.erase(s.size(), 1);
  if(s == u)
    cout << "Yes";
  else
    cout << "No";
}
