// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve();
int main() { solve(); return 0; }

vector<string> Z { "NO", "YES" };

#include <set>
void solve() {
  string s;
  cin >> s;
  string u = s;
  reverse(u.begin(), u.end());  
  int n = s.size();
  int cnt = 0;
  loop(i,0,n) cnt += s[i]!=u[i];
  cout << cnt/2 << endl;
}
