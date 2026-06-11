// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n; cin >> n;
  vector<int> A(n);
  loop(i,0,n) cin >> A[i];
  sort(A.begin(), A.end());
  cout << A[n/2] - A[n/2-1] << endl;
  return 0;
}
