#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n,m;
  cin >> n >> m;
  vector<int> s(m),c(m);
  rep(i,m) cin >> s[i] >> c[i];
  int ans=-1;

  for(int i=1000; i>=0; i--){
    string S=to_string(i);
    bool ok=true;
    if(sz(S)!=n) ok=false;
    for(int j=0; j<m; j++){
      if(S[s[j]-1]!=(char)(c[j]+'0')) ok=false;
    }
    if(ok) ans=i;
  }
  cout << ans << endl;
  return 0;
}
