#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, int> mp;
  rep(i,0,N-1) {
    int A;
    cin >> A;
    mp[A]++;
    if (1 < mp[A]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}
