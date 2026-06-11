#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define Debug(X) cout << #X << " = " << X << '\n'
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n, m;

ll lcm(ll x, ll y){
  return (x * y) / __gcd(x, y);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  cin >> n >> m;
  ll t = 1;
  vector<int> a(n+1);
  For(i, 1, n) {
    cin >> a[i]; a[i] /= 2; t = lcm(t, a[i]);
    if (t > m){
      cout << 0; return 0;
    }
  }
  For(i, 1, n){
    if ( (t / a[i]) % 2 == 0){
      cout << 0; return 0;
    }
  }
  cout << ((m / t) + 1) / 2;

}
