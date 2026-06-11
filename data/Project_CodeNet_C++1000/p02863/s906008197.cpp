#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


int main() {
  int N,T; cin >>N >>T;
  vector<int> A(N),B(N); rep(i, N) cin >>A[i] >>B[i];
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(T+1, vector<int>(2, -1000000000)));
  // dp[i][j][k] := i番目までの料理をj分以内に食べるときの満足度の最大値。
  //  最後に注文するものは時間を気にしなくてよいが、k=1のときはそれが既に決まっているとする。
  //  但しk=1とできるのはj < T の時に限る。
  dp[0][0][0] = 0;
  for (int i=0; i<N; i++){
    for (int j=0; j<=T; j++){
      for (int k=0; k<2; k++){
        if (dp[i][j][k] == -1000000000) continue;
        // 普通にこの料理を選ばない
        chmax(dp[i+1][j][k], dp[i][j][k]);
        if (k == 0){
          // 普通にこの料理を選ぶ。j<=T。
          if (j+A[i] <= T) chmax(dp[i+1][j+A[i]][k], dp[i][j][k] + B[i]);
          // この料理を最後の料理とする。j<=T-1。
          if (j < T) chmax(dp[i+1][j][1], dp[i][j][k] + B[i]);
        }else if (k == 1){
          // 普通にこの料理を選ぶ。j<T。
          if (j+A[i] < T) chmax(dp[i+1][j+A[i]][k], dp[i][j][k] + B[i]);
        }
      }
    }
  }
  int res = 0;
  for (int j=0; j<=T; j++){
    for (int k=0; k<2; k++){
      chmax(res, dp[N][j][k]);
    }
  }
  cout <<res <<endl;
}
