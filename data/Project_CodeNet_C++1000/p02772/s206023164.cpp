#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  bool yes = 1;
  rep(i,n){
    if(a[i]%2==0){
      if(a[i]%3==0||a[i]%5==0) continue;
        yes=0;
        break;
    }
  }
  if(yes) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
  return 0;
}
