// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n; cin >> n;
  set<string> S;
  loop(i,0,n) {
    string s;
    cin >> s;
    S.insert(s);
  }
  cout << S.size() << endl;
  return 0;
}
