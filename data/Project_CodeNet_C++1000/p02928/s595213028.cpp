#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int mod = 1000000007;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<int> A(n);
  rep(i,n) cin >> A[i];
  ll ans = 0;
  k %= mod;
  rep(i,n) {
    ll left = 0, right = 0;
    rep(j,n) {
      if (A[i] > A[j]){
        if (i < j) right++;
        else if (j < i) left++;
      } 
    }
    ans += right*k % mod;
    ans %= mod;
    ans += (k-1)*k/2 % mod * (left + right) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
