#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int n, m, total=0, can=0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    total += a[i];
  }
  rep(i,n){
    if(a[i]*4*m<total) continue;
    can++;
  }
  if(can >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}