// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
void solve(); int main() { solve(); return 0; }

void solve() {
  vector<bool> A(4, false);
  loop(i,0,2) {
    int a;
    cin >> a;
    A[a] = true;
  }
  
  loop(i,1,4) {
    if (!A[i]) {
      cout << i << endl;
      return;
    }
  }
}
