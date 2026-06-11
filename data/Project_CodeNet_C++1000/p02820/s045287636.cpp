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
  int n, k, r, s, p;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  ll rec = 0;
  rep(i,sz(t)){
    if (t[i] == 'r') rec += p;
    else if(t[i]=='s') rec += r;
    else rec += s;
  }
  rep(i,sz(t)-k){
    if(t[i]==t[i+k]){
      t[i + k] = 'x';
      if (t[i] == 'r') rec -= p;
      else if(t[i]=='s') rec -= r;
      else rec -= s;
    }
  }
  cout << rec << endl;
  return 0;
}