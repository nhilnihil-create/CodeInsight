#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> m(n+1);
  rep(i,n) m[i+1] = (m[i]+a[i])%k;
  rep(i,n+1) m[i] = (m[i]-i+i*k)%k;

  ll ans = 0;
  map<int,int> cnt;
  int l = 0;
  rep(r,n+1){
    if(r-l+1>k){
      cnt[m[l]]--;
      ++l;
    }
    ans += cnt[m[r]];
    cnt[m[r]]++;
  }
  cout << ans << endl;
}
