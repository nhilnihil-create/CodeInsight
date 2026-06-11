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

map<ll,int> mp; 

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  bool b = true;
  rep(i,n) {
    ll t = a[i];
    if (mp[t]) {
      b = false;
      break;
    } else {
      mp[t]++;
    }
  }
  cout << (b ? "YES" : "NO") << endl;
}

int main() {
  solve();
  return 0;
}