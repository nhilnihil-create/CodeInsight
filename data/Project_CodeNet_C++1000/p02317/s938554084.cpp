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


void solve(){
  int N; cin >>N;
  vector<int> A(N, INT_MAX);
  rep(i, N){
    int a; cin >>a;
    *lower_bound(all(A), a) = a;
  }
  int res = 0;
  rep(i, N) if (A[i] < INT_MAX) res = i+1;
  cout <<res <<endl;
}

template<class T> inline void compress1(vector<T> &a){
  vector<T> com = a;
  sort(all(com));
  com.erase(unique(all(com)), com.end());
  rep(i, a.size()) a[i] = lower_bound(all(com), a[i]) - com.begin();
}

// Segment木によるRMQの実装------------------------------------

template<class T> struct SegmentTree {
  int N;
  vector<T> node;

  SegmentTree(int n_){   // 初期化
    N = 1; while (N < n_) N *= 2; // 要素数を2のべき乗に
    node.assign(2*N-1, 0);
  }

  // k番目(0-indexed)の値をaに変更
  void update(int k, T a){
    k += N-1; node[k] = a;
    while (k > 0){
      k = (k-1) / 2;
      node[k] = max(node[k*2+1], node[k*2+2]);
    }
  }

  // [a,b)の最大値を求める。k,l,r := node[k] が [l,r) に対応づいている
  // 外からは getmin(a,b) として呼んでよい
  T getmax(int a,int b,int k=0,int l=0,int r=-1){
    if (r == -1) r = N;
    // [a,b) と [l,r) が交差しなければ影響しない値を返す
    if (r <= a || b <= l) return 0;
    // [a,b) が [l,r) を完全に含むなら自分の値を返す
    if (a <= l && r <= b) return node[k];
    // そうでなければ2つの子の最小値を返す
    T vl = getmax(a, b, k*2+1, l, (l+r)/2);
    T vr = getmax(a, b, k*2+2, (l+r)/2, r);
    return max(vl, vr);
  }
};

void solve2(){
  int N; cin >>N;
  vector<int> A(N); rep(i, N) cin >>A[i];
  compress1(A);
  vector<int> dp(N+1, 0);
  // dp[i] := 最後の要素が i であるような LIS の長さの最大値
  SegmentTree<int> st(N);
  rep(i, N){
    // 0 <= k < A[i] なる k のなかで A[k] が最大になる k を k' とおくと、
    // dp[A[i]] = max(dp[A[i]], dp[k'] + 1);
    // あるいは更新しないか
    int tmp = st.getmax(0, A[i]) + 1;
    if (tmp > dp[A[i]]){
      dp[A[i]] = tmp; st.update(A[i], tmp);
    }
  }
  int res = st.getmax(0, N);
  cout <<res <<endl;
}

int main() {
  // solve();
  solve2();
}
