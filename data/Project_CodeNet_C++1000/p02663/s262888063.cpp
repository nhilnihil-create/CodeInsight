#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define inf 999999
#define EPS (1e-7)
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define ALL(a)  a.begin(),a.end()
#define RALL(a) a.begin(),a.end(),greater<int>()
#define PI acos(-1.0)
const ll MOD = 1e9+7;
const int MAX = 10000000;
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
//next_permutation(ALL(p));
//typedef priority_queue<int> pque;//これは大きい順
//typedef priority_queue<int, vector<int>, greater<int>> pque;//これは小さい順
//factorizeは、素因数分解用の関数

int main(){
	int h1,m1,h2,m2,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  int ans = (h2+24)*60+m2 - h1*60-m1;
  ans %= 60*24;
  ans -= k;

  cout << ans << endl;

  return 0;
}
