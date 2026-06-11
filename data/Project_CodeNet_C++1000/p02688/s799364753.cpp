#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int n, k, d, x, ans=0;
  cin >> n >> k;
  vector<int> a(n,0);
  rep(i,k){
    cin >> d;
    rep(j,d){
      cin >> x;
      x--;
      a[x]++;
    }
  }
  rep(i,n)if(a[i]==0) ans++;
  cout << ans << endl;
  return 0;
}