#include <bits/stdc++.h>
#include <vector>
#include <set>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  
  if(n <= 10) r += 100 * (10 - n);
  
  cout << r << endl;
  
  return 0;
}
