#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
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
void hey(){ cout <<"hey" <<endl; }


int main() {
  string s; cin >>s;
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(13, 0));
  // dp[i][j] := 先頭からi桁を考えて、13で割った余りがjものの個数
  dp[0][0] = 1;
  rep(i, n){
    // s[i] == '?'なら10個考える
    if (s[i] == '?'){
      rep(j, 13){
        rep(d, 10){
          int nj = (10*j+d)%13;
          dp[i+1][nj] += dp[i][j];
          dp[i+1][nj] %= MOD;
        }
      }
    }else{
      int d = s[i] - '0';
      rep(j, 13){
        int nj = (10*j+d)%13;
        dp[i+1][nj] += dp[i][j];
        dp[i+1][nj] %= MOD;
      }
    }
  }
  ll res = dp[n][5];
  cout <<res <<endl;
}
