#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<long long> VLL;
typedef vector<pair<int,int>> VP;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define inf 999999
#define EPS (1e-7)
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,n) for(int i=1;i<=(int)(n);i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define ALL(a)  a.begin(),a.end()
#define RALL(a) a.begin(),a.end(),greater<int>()
#define ROT(a) a.begin(),a.begin()+1,a.end()
#define RROT(a) a.begin(),a.end()-1,a.end()
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
#define sz(a) a.size()
const ll MOD = 1e9+7;
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
//cout << 'H' << endl;
/*--------------------------------------------*/

int main(){
  //cout.precision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N;cin >> N;
  vector<pair<ll,ll>> x(N);
  rep(i,N) cin >> x[i].first >> x[i].second;
  sort(ALL(x));
  
  pair<ll,ll> a[100][100];
  
  map<pair<ll,ll>,ll> mp;
  
  rep(i,N){
    for(int j = i + 1;j < N;j++){
        a[i][j].first = x[j].first - x[i].first;
        a[i][j].second = x[j].second - x[i].second;
        mp[MP(a[i][j].first,a[i][j].second)]++;
    }
  }
  
  int max = 0;


  for(auto i:mp){
    //cout << i.first.first<< ' ' << i.first.second << ' ' << i.second << endl;
    chmax(max,i.second);
    //cout << max << endl;
  }
  
  
  cout << N - max << endl;
  
  
}