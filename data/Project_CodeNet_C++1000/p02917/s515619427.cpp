#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  int res = 0;
  int a = 10000000000;
  int b = 0;
  rep(i,N-1){
    cin >> b;
    res += min(a,b);
    a = b;
  }
  res += a;
  
  cout << res << endl;
}