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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if ((a[i] + a[j] > a[k])  && (a[i] + a[k] > a[j]) && (a[k] + a[j] > a[i]) && (a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i])) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}