#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VLL a(n);
  VLL b(n);

  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  priority_queue<PLL> que;
  rep(i,n){
    if(a[i] > b[i]){
      cout << -1 << "\n";
      return 0;
    }
    que.push({b[i],i});
  }

  ll ans = 0;
  while(!que.empty()){
    PLL p = que.top();
    que.pop();
    int idx = p.second;
    if(b[idx] == a[idx]) continue;

    ll sum = b[(idx+1)%n] + b[(idx-1+n)%n];
    ll cnt = (b[idx] - a[idx]) / sum;
    if(cnt == 0){
      cout << -1 << endl;
      return 0;
    }
    b[idx] -= sum * cnt;
    ans += cnt;
    que.push({b[idx],idx});
  }
  cout << ans << endl;
  return 0;
}
