//includes
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<iomanip>
#include<numeric>
#include<assert.h>
#include<cstring>
#include<unordered_map>
#include<bitset>

//macros and consts
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORE(i,a) for(auto &i : a)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define Fi first
#define Se second
#define INF 1e9
#define llINF (1LL<<60)
#define mINF -1e9
#define mllINF -(1LL<<60)
#define endl "\n"
#define CONT continue
#define BRK break
#define modulo(n, m) (((n)%(m)+(m))%m)

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vc = std::vector<char>;
using vll = std::vector<long long>;
using vs = std::vector<string>;
using Mi = map<int,int>;
using Mll = map<ll,ll>;
using UMi = unordered_map<int,int>;
using UMll = unordered_map<ll,ll>;
using Pi = pair<int,int>;
using Pll = pair<ll,ll>;
using vPi = vector<Pi>;
using vPll = vector<Pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using pqgi = priority_queue<int,vector<int>,greater<int>>;
using pqsi = priority_queue<int,vector<int>,less<int>>;
using pqgll = priority_queue<int,vector<int>,greater<int>>;
using pssll = priority_queue<int,vector<int>,less<int>>;
template<class T>
using vec = vector<T>;
#define int long long

int N,K;
int dp[305][305];
//here begins your code
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> K;
  int M = N - K;

  vector<int> h(N);
  REP(i,N){
  	cin >> h[i];
  }
  h.insert(h.begin(),0);
  REP(i, N + 1){
  	REP(j, M + 1){
  		dp[i][j] = llINF;
  	}
  }
  dp[0][0] = 0;
  for(int i = 1; i <= N ; i++){
  	REP(j,M)   {
  		int now = llINF;
  		REP(k, i){
  			now = min(now, dp[k][j] + max(0LL,h[i] - h[k]));
  		}
  		dp[i][j + 1] = now;
  	}
  }

  int ans = llINF;
  REP(i, N+1){
  	ans = min(ans,dp[i][M]);
  }
  cout << ans << endl;

  //check types
  //do not eb if you resize
  //resize before you access by idx
  return 0;
} 