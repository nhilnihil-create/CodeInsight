#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n, k;
  cin >> n >> k;
  ll ans = min(n%k, abs(n%k - k));
  cout << ans << endl;
}
