#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  ll a, b, k;
  cin >> a >> b >> k;
  if ((k < a) ) {
    cout << a - k << " " << b << endl;
  } else if (k < a + b) {
    cout << 0 << " " << b - (k - a) << endl;
  } else {
    cout << 0 << " " << 0 << endl;
  }
}

int main() {
  solve();
  return 0;
}