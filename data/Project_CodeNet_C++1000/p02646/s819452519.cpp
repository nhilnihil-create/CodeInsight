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
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if(t*(v-w)>=abs(a-b)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}