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


typedef pair<double,double> Pd;

int n;

Pd solve(Pd a, Pd b){
  // a, bを1辺とする正三角形のもう一つの頂点が求めるやつ
  // ただし案時計回りにa, b, cとする
  double a1,a2,b1,b2;
  a1 = a.first; a2 = a.second; b1 = b.first; b2 = b.second;
  Pd c;
  if (a2 == b2){
    // a, b が水平の場合
    c.first = (a1 + b1) / 2;
    c.second = a2;
    double dy = b1 - a1;
    c.second += dy * (double)sqrt(3.0) / 2;
  }else if (a1 < b1){
    c.second = max(a2, b2);
    double dx = (b1 - a1) * 2;
    if (a2 < b2) c.first = b1 - dx;
    else c.first = a1 + dx;
  }else if (a1 > b1){
    c.second = min(a2, b2);
    double dx = abs(b1-a1);
    if (a2 < b2) c.first = b1-dx;
    else c.first = a1+dx;
  }
  return c;
}

void dfs(Pd a, Pd b, int depth){
  // 引数a,bがn=depthのときの始点と終点。
  if (n == depth){
    // 被りを防ぐために始点のみ出力すう
    cout <<fixed <<setprecision(12) <<a.first <<" " <<a.second <<endl;
    return;
  }
  // a, b は4つの領域に分けられる
  Pd a1;
  a1.first = (a.first * 2 + b.first) / 3;
  a1.second= (a.second* 2 + b.second)/ 3;
  Pd a3;
  a3.first = (a.first + b.first * 2) / 3;
  a3.second = (a.second + b.second * 2) / 3;
  Pd a2 = solve(a1, a3);
  dfs(a, a1, depth+1);
  dfs(a1, a2, depth+1);
  dfs(a2, a3, depth+1);
  dfs(a3, b, depth+1);
}

int main() {
  cin >>n;
  dfs(Pd(0.0, 0.0), Pd(100.0, 0), 0);
  cout <<fixed <<setprecision(12) <<100.0 <<" " <<0.0 <<endl;
}
