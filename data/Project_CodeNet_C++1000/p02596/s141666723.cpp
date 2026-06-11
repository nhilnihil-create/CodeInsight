#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll k;
  cin >> k;
  ll s = 7LL;
  ll d = 7LL;
  rep(i,1000000) {
    if(d%k==0) {
      cout << i+1 << endl;
      return 0;
    }
    s *= 10;
    s %= k;
    d += s;
    d %= k;
  }
  cout << -1 << endl;
  return 0;
}