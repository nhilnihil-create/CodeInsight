#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
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


int N;

ll merge_sort(vector<int> &A){
  int n = A.size();
  if (n == 1) return 0;
  int n2 = n/2;
  vector<int> B(n2); rep(i, n2) B[i] = A[i];
  vector<int> C(n-n2); rep(i, n-n2) C[i] = A[n2+i];
  ll res = merge_sort(B);
  res += merge_sort(C);

  int bi = 0, ci = 0;
  for (int i=0; i<n; i++){
    if (bi < n2 && (ci == n-n2 || B[bi] < C[ci])) A[i] = B[bi++];
    else{
      res += n2 - bi;
      A[i] = C[ci++];
    }
  }
  return res;
}

int main() {
  cin >>N;
  vector<int> A(N); rep(i, N) cin >>A[i];
  ll res = merge_sort(A);
  cout <<res <<endl;
}

