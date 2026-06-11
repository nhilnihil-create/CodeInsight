#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int h,n;
  cin >> h >> n;
  vector<int> a(n);
  
  REP(i,n) cin >> a[i];
  
  int sum = 0;
  
  REP(i,n) sum += a[i];
  
  
  if(sum >= h) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
