#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans=0;
  rep(i,n-1) {
    for(int j=i+1; j<n; j++) {
      ans+=a[i]*a[j];
    }
  } 

  cout << ans << endl;
}
