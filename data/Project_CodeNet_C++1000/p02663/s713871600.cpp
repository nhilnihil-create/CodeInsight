#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  
  auto totalMin = (h2 - h1) * 60 + (m2 - m1);
  
  cout << totalMin - k << endl;
}
