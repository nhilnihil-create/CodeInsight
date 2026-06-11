#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define PI 3.14159265359
using namespace std;

int main(){
  int n, m, total=0, a;
  cin >> n >> m;
  rep(i,m){
    cin >> a;
    total += a;
  }
  if(n >= total) cout << n - total << endl;
  else cout << -1 << endl;
  return 0;
}
