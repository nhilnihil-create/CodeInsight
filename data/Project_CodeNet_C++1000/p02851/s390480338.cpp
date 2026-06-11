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
  int N; ll K; cin >>N >>K;
  vector<ll> A(N); rep(i, N) cin >>A[i];
  vector<ll> Asum(N+1, 0);
  rep(i, N) Asum[i+1] = Asum[i] + A[i];
  /*
  0 <= i < j <= N を満たす正の整数i,jの組について、
  (Asum[j]-Asum[i]) % K = j-i を満たすものを数え上げよ。
  * Asum[j] := [0, j)
  * Asum[i] := [0, i)
  * Asum[j]-Asum[i] := [i, j)
  
  Asum[j]-Asum[i] = j-i + x * K
  Asum[j]-j = Asum[i]-i + x*K
  (Asum[j]-j)%K = (Asum[i]-i)%K
  */
  
  for (int i=0; i<=N; i++){
    Asum[i] += K*i - i;
    Asum[i] %= K;
  }
  map<ll,ll> mods;
  ll res = 0;
  for (int i=0; i<=N; i++){
    if (i >= K) mods[Asum[i-K]]--;
    res += mods[Asum[i]];
    mods[Asum[i]]++;
  }
  cout <<res <<endl;
}
