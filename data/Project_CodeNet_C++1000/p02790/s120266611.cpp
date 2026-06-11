/*
 * atcoder/abc089/b.cpp
 */

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

#define ld long double
void solve() {
  string s, t;
  int a, b;
  cin >> s >> t;
  a = stoi(s); b = stoi(t);
  string n = "", m = "";
  loop(i,0,a) n += t;
  loop(i,0,b) m += s;
  if (n > m) swap(n, m);
  cout << n << endl;
}
