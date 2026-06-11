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

vector<string> Z { "No", "Yes" };

#include <set>
void solve() {
  string s, t;
  cin >> s >> t;
  int count = 0;
  int n=3;
  loop(i,0,n) count += s[i]==t[i];
  cout << count << endl;
}
