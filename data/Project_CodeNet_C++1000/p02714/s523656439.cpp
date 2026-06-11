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
  string s;
  cin >> n >> s;
  ll r = 0, b = 0, g = 0;
  rep(i,n) {
    if (s[i] == 'R') r++;
    if(s[i]=='G') g++;
    if(s[i]=='B') b++;  }
  ll ans = r * g * b;
  rep(j,n){
    for(int i=0; i<j; i++){
      int k = 2 * j - i;
      if(k < n && s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i]){
        ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
