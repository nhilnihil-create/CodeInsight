#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  bool ans  = false;

  sort(a.begin(),a.end());
  rep(i,n-1){
    if(a[i] == a[i+1]) ans = true;
  }

  if(ans) cout << "NO";
  else cout << "YES";

}
