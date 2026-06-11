#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n+1);
  rep(i,n) cin >> a[i+1];
  map<int, int> mp;
  ll ans=0;
  for(int i=1; i<=n; i++){
    int sa = i - a[i];
    ans += mp[sa];
    int wa = i + a[i];
    mp[wa]++;
  }
  cout << ans << endl;
}
