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
  int n = s.size();
  int cnt = 0;
  int l=0, r=n-1;
  while (l<r) {
    cnt += s[l++]!=s[r--];
  }
  cout << cnt << endl;
}
