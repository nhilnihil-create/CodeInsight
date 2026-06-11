#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n,k;
  cin >> n >> k;
  vi h(n);
  rep(i,n) cin >> h[i];
  int ans=0;
  rep(i,n){
    if(k<=h[i]) ans++;
  }
  cout << ans << endl;
}