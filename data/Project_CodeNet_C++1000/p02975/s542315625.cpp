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
template<class T> inline T power(T a,T b,T m=numeric_limits<T>::max()){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


bool solve(int N, vector<ll> &a){
  sort(all(a));
  if (a[N-1] == 0) return true;
  vector<ll> b = a;
  b.erase(unique(all(b)), b.end());
  if (N%3 != 0) return false;
  if (b.size() > 3) return false;

  for (int i=0;   i<N/3;   i++) if (a[i] != a[0])   return false;
  for (int i=N/3; i<2*N/3; i++) if (a[i] != a[N/3]) return false;
  for (int i=2*N/3; i<N; i++) if (a[i] != a[2*N/3]) return false;

  if ((a[0] ^ a[N/3]) == a[2*N/3]) return true;
  return false;
}

int main() {
  int N; cin >>N;
  vector<ll> a(N); rep(i, N) cin >>a[i];
  bool res = solve(N, a);
  cout <<(res ? "Yes" : "No") <<endl;
}