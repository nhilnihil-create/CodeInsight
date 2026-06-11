#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,k;
  cin >> n >> k;
  if(k == 1) cout << 0 << endl;
  else cout << n-k << endl;
  return 0;
}
