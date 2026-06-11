#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  bool ans = false;

  rep(i,n){
    if(a[i]%2 == 1) continue;
    if(a[i]%3 != 0 && a[i]%5 != 0) ans = true;
  }

  if(ans) cout << "DENIED" << endl;
  else cout << "APPROVED" << endl;
}
