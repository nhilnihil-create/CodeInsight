#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int k,n;
  cin >> k >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  int ans = 0;
  rep(i,n){
    if(i == n-1) ans = max(ans, k-a[n-1]+a[0]);
    else ans = max(ans, a[i+1]-a[i]);
  }
  cout << k-ans << endl;
}
