#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// ただのセグメント木 (区間最大, long long)
struct SegmentTree {
private:
  int n;
  vector<ll> node;

public:
    // 元配列 v をセグメント木で表現する
  SegmentTree(vector<ll> v) {
    // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    // セグメント木全体で必要なノード数は 2n-1 個である
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, -1); // 最小値は-1

    // 最下段に値を入れたあとに、下の段から順番に値を入れる
    // 値を入れるには、自分の子の 2 値を参照すれば良い
    for(int i=0; i<sz; i++) node[i+n-1] = v[i];
    for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
  }

  void update(int x, ll val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = max(node[2*x+1], node[2*x+2]);
    }
  }

    // 要求区間 [a, b) 中の要素の最大値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる
  ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l) return -1;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
    return max(vl, vr);
  }
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

   int N;
   ll M, V, P;
   cin >> N >> M >> V >> P;

   vector<ll> a(N);
   rep(i, N) cin >> a[i];

   sort(a.rbegin(), a.rend());

  int ans = 0;
  
  SegmentTree seg(a);

  vector<ll> suma(N+1);
  suma[0] = 0;
  rep(i, N){
    suma[i+1] = suma[i] + a[i];
  }

  rep(i, N){

    if(i < P){
      ans++;
      continue;
    }

    // i番目について
    // もし P-1 ~ i番目の最大値が a[i] + M より大きければだめ
    if(seg.getmax(P-1, i) > a[i] + M) continue;

    // 投票せざるをえない人たち

    ll H = max(0LL, V - (P-1 + (N-i)));

    if(H*M+suma[i]-suma[P-1] <= (a[i]+M)*(i-P+1)){
      ans++;
    }

  }

  cout << ans << endl;

  return 0;
}
