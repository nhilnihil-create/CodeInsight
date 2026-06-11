#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<int> v(1000000);
  rep(i,n){
    cin >> v[i];
  }

  int min = 10000000;
  int ans = 0;
  rep(i,n){
    if(min > v[i]){
      min = v[i];
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
