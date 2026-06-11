#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int M = 1000002;

int main() {
  ll n;
  cin >> n;
  // vector<ll> a(n);
  vector<int> array(M);
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n) {
    if(array[a[i]] != 0){
      array[a[i]] = 2;
      continue;
    }
    for(int j = a[i]; j < M; j += a[i]) array[j]++;
  }
  int ans = 0;
  for(int ar : a) {
    if(array[ar] == 1) ++ans;
  }
  cout << ans << endl;

  return 0;
}
