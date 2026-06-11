// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n; cin >> n;
  vector<int> A(n), B(n), C(n-1);
  loop(i,0,n) cin >> A[i];
  loop(i,0,n) A[i]--;
  loop(i,0,n) cin >> B[i];
  loop(i,0,n-1) cin >> C[i];
  int prev = -1;
  int t = 0;
  for (auto&&i: A) {
    if (prev + 1 == i) t += C[prev];
    prev = i;
    t += B[i];
  }
  cout << t << endl;
  return 0;
}
