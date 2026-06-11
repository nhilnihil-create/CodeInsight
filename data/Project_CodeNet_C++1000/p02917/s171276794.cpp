#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  
  vi b(n-1);
  rep(i,n-1) cin >> b.at(i);
  
  vi a(n);
  rep(i,n-1){
    if (i == 0){
      a.at(i) = b.at(i);
      a.at(i+1) = b.at(i);
      continue;
    }
    a.at(i) = min(a.at(i), b.at(i));
    a.at(i+1) = b.at(i);
  }

  int ans = 0;
  rep(i,n) ans += a.at(i);
  cout << ans << endl;
  return 0;
}
