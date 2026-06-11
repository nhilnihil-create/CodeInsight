#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // エラトステネスの篩の入力配列でふるいをしていくバージョンをやればOK
  vector<int> cnt(1000005);
  vector<bool> p(1000005, true);
  rep(i, n) {
    int v = a[i];
    cnt[v]++;
    if (cnt[v] >= 2) continue;
    for (int j = v + v; j <= 1000005; j += v) p[j] = false;
  }

  int ans = 0;
  rep(i, n) {
    int v = a[i];
    if (cnt[v] == 1 && p[v]) ans++;
  }
  cout << ans << endl;
}