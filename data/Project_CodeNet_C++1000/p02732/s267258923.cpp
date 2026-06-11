#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll func(ll a) {
  if (a <= 1) return 0;
  return a * (a - 1) / 2;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  vector<int> mp(n);
  rep(i,n){
    cin >> v[i];
    mp[v[i] -  1]++;
  }
  ll sum = 0;
  for(ll p: mp) {
    sum += func(p);
  }
  rep(i,n) {
    ll temp = sum;
    temp -= func(mp[v[i] - 1]);
    temp += func(mp[v[i] - 1] - 1);
    cout << temp << endl;
  }
}

int main() {
  solve();
  return 0;
}