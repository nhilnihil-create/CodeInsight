#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b(n);
  rep(i,n) b[i]=a[i];
  sort(begin(b),end(b));
  int c=0;
  rep(i,n) {
    if(a[i]!=b[i]) c++;
  }
  if(c<=2) cout << "YES" << endl;
  else cout << "NO" << endl;
}