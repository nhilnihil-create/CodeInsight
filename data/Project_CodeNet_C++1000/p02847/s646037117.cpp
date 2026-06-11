// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve(); int main() { solve(); return 0; }

void solve() {
  map<string, int> M {
    { "SUN", 7 },
    { "MON", 6 },
    { "TUE", 5 },
    { "WED", 4 },
    { "THU", 3 },
    { "FRI", 2 },
    { "SAT", 1 },
  };
  string s; cin >> s;
  cout << M[s] << endl;
}
