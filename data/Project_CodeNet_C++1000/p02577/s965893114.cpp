#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; ++i)

main(void) {
  string n;cin>>n;
  int res=0;
  for (int i = 0; i < n.length(); i++) {
  	res += n[i] - '0';
  }
  if(res%9==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}