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
  int N; ll M; cin >>N >>M;
  vector<ll> A(N); rep(i, N) cin >>A[i];
  // 任意のA_iに対して以下の条件を満たす正の整数xの個数を求めよ。
  // X = A_i * (p + 0.5) を満たす負でない整数pが存在する
  rep(i, N) A[i] /= 2;
  // 任意のA_iに対して以下の条件を満たす正の整数xの個数を求めよ。
  // X = A_i * (2p + 1) を満たす負でない整数pが存在する
  // X = A_i * P を満たす正の奇数Pが存在する

  // X は A_iの公倍数であり、かつA_i * 奇数 で表される

  // まず最小公倍数を求めれば良さそう
  ll l = 1;
  rep(i, N){
    l = lcm(l, A[i]);
    if (l > M){
      // 最小公倍数がMを超えたとするとM以下の公倍数は存在しない
      cout <<0 <<endl; return 0;
    }
  }
  // 最小公倍数がl
  // 全てのA_iの奇数倍数であることを確認する。そうでなければ0
  rep(i, N){
    if ((l/A[i])%2 == 0){
      cout <<0 <<endl; return 0;
    }
  }
  // 条件を満たしていれば、M以下のlの倍数のうちl * 奇数 の形で示されるものの個数が答え
  ll res = (M/l + 1) / 2;
  cout <<res <<endl;
}
