#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vi h(n);
  rep(i, n)cin >> h[i];

  sort(h.begin(), h.end());
  ll ans=0;
  rep(i, n-k)ans+=h[i];

  cout << ans << endl;

  return 0;
}