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

#define ull unsigned long long
void solve() {
  int n,k; cin >> n >> k;
  int count = 1;
  while (n/k!=0) count++,n/=k;
  cout << count << endl;
}
