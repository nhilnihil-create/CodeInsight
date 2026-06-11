#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  ll starta, v, startb, w, t;
  cin >> starta >> v >> startb >> w >> t;

  ll dist = abs(starta - startb);
  bool ans = false;
  if (dist == 0) ans = true;
  if (v * t - w * t >= dist) ans = true;
  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}