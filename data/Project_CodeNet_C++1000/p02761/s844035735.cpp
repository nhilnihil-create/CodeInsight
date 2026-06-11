#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
//V,Pは大文字i,l,bは小文字
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pll = pair<ll, ll>;
const ll mod = 1000000007;
const ll inf = 1000000000000;//10の12乗

int main() {
  int n,m;
  cin >> n >> m;
  Vi v(3,-1);
  bool b=1;
  rep(i,m){
    int x,y;
    cin >> x >> y;
    x--;
    if(v[x]!=-1&&v[x]!=y) b=0;
    v[x]=y;
    if(x==0&&y==0&&n!=1) b=0;
  }
  if(v[0]==-1)chmax(v[0],1);
  chmax(v[1],0);
  chmax(v[2],0);
  if(n==1&&m==0) v[0]=0;
  if(b)rep(i,n) cout << v[i];
  else cout << -1 << endl;
}