#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for(int i = 0;i < (n);++i)
#define RREP(i, n) for(int i = (n)-1; i >= 0; --i)
#define RANGE(i, a, b) for(int i=(a);i<(b);++i)

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define pque priority_queue
#define umap unordered_map
#define uset unordered_set
#define BIG 2000000000
#define VERYBIG 1000000000000000ll
#define PI 3.1415926
#define coutdb cout<<fixed<<setprecision(15)

const int dx[]={1,0,-1,0,1,1,-1,-1}, dy[]={0,-1,0,1,1,-1,1,-1};
const long long MOD = 1e9+7;

// typedef int_fast64_t ll;
#define int long long

template<typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template<typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template<typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> INTP;
typedef vector<int> INTV;
struct edge2 {int to, cost;};
struct edge3 {int from, to, cost;};

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, A[100000]; cin >> N;
  int allxor = 0;
  REP(i, N){
    cin >> A[i];
    allxor ^= A[i];
  }
  REP(i, N) A[i] &= ~allxor;

  int rank = 0;
  for(int i = 59; i >= 0; i--){
    int j;
    for(j = rank; j < N; j++){
      if(A[j] & (1ll << i)) break;
    }
    if(j == N) continue;
    if(j > rank) A[rank] ^= A[j];
    for(j = rank+1; j < N; j++){
      chmin(A[j], A[j] ^ A[rank]);
    }
    rank++;
  }
  int ans = 0;
  REP(i, N){
    chmax(ans, ans ^ A[i]);
  }
  ans *= 2; ans += allxor;
  cout << ans << endl;
}