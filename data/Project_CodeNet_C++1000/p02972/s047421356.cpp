#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n;cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> ball(n+1,0);

  for (int i = n; i >= 1;i--){
    int cnt = 0;
    // iの倍数のボールの和
    for (int j = i; j <= n; j += i) {
      if (ball[j] == 1) cnt++;
    }
    if (cnt % 2 != a[i]) ball[i] = 1;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) if (ball[i]) ans.pb(i);
  cout << sz(ans) << endl;
  rep(i,sz(ans)) cout << ans[i] << " ";
  return 0;
}