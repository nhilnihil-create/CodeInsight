#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
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


// BIT-------------------------------------------------------

// [0, N-1]ではなく[1, N], 1-indexed
int M;
const int MAX_N = 200000;
vector<ll> bit(MAX_N+1); // bit[1]...bit[N]を使用

ll sum(int a){          // 1～a (1-indexed)の和を求める
  ll ret=0;
  for (int i=a; i>0; i -= i & -i) ret += bit[i];
  return ret;
}

void add(int a, ll x){  // a番目(1-indexed)に x を加える
  for (int i=a; i<=M; i += i & -i) bit[i] += x;
}


int main() {
  int N; cin >>N >>M;
  vector<bool> work(M+1, true);
  work[0] = false;
  // i日目に仕事を受けられるか
  // BITの都合で1-indexedにする
  for (int i=1; i<=M; i++) add(i, 1);
  // 働けるところはBIT上で1にしておく

  vector<pair<ll,ll>> A(N);
  rep(i, N) cin >>A[i].second >>A[i].first;
  rep(i, N) A[i].second--; // BITの都合でデクリメント
  sort(all(A)); reverse(all(A));
  // 報酬が多い順にソート

  ll res = 0;

  rep(i, N){
    ll cost = A[i].first;
    ll day = M - A[i].second;
    // day日かそれより前に仕事を受ければ間に合う
    // day日丁度に受けられるなら受ける
    if (day <= 0) continue;
    if (work[day]){
      res += cost;
      work[day] = false;
      add(day, -1);
    }else{
      // day日より前のうち、仕事を受けられる最も遅い(jが大きい)ところに仕事を入れる
      // BIT上二分探索とかで。
      int s = sum(day);
      if (s == 0) continue; // day日より前で仕事を受けられる日はない
      // BIT上での和がsになる最大のやつを二分探索。そこに仕事を入れる
      int ok = M+1, ng = 0;
      while (abs(ok - ng) > 1){
        int mid = (ok+ng)/2;
        if (sum(mid) >= s) ok = mid;
        else ng = mid;
      }
      res += cost;
      work[ok] = false;
      add(ok, -1);
    }
  }
  cout <<res <<endl;

}
