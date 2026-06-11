#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  int nextnum = 1;
  rep(i, n) {
    int a;
    cin >> a;
    if(a == nextnum) ++nextnum;
  }
  
  if (nextnum == 1) cout << -1 << endl;
  else cout << n-nextnum+1 << endl;
      
  return 0;
}
