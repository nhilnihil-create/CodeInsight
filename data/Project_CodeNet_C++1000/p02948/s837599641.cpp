#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-10;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


//ここから編集
ll GCD(ll a, ll b){
    
    if(b == 0) return a;
    return GCD(b, a%b);
}

template<typename T = int> struct BIT{
  vector<T> node;

  int N;
  BIT(int n){
    N = n;
    node.resize(N+1);
  }

  void add(int i, T x){
    i++;
    while(i <= N){
      node[i] += x;
      i += (i & -i);
    }
  }

  T sum(int i){
    T res = 0;
    while(i > 0){
      res += node[i];
      i -= (i & -i);
    }
    return res;
  }

  

};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int N, M; cin >> N >> M;
  vector<vector<ll>> vp(100010);

  REP(i,N){
    ll a, b;cin >> a >> b;
    if(M-a < 0)continue;
    vp[M-a].push_back(b);
  }

  priority_queue<ll> pq;
  ll ans = 0;
  for(int i=M; i>=0; i--){
    for(int j=0; j < vp[i].size(); j++){
      pq.push(vp[i][j]);
    }

    if(pq.size()){
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
