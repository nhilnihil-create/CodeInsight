#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i < (int)(n); i++)
#define repd(i,n) for (int i = n-1; i >= 0; i--)
#define rrepd(i,k,n) for (int i = n-1; i >= (int)(k); i--)
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
  VVi v(3,Vi(3));
  VVi whe(100,Vi(2,-1));
  VVb bingo(3,Vb(3,0));
  rep(i,3)rep(j,3){
    int x;
    cin >> x;
    whe[x-1][0]=i;
    whe[x-1][1]=j;
  }
  int n;
  cin >> n;
  rep(i,n){
    int x;
    cin >> x;
    x--;
    if(whe[x][0]==-1) continue;
    int a=whe[x][0],b=whe[x][1];
    bingo[a][b]=1;
  }
  bool ok=0;
  rep(i,3){
    bool tate=1;
    rep(j,3){
      if(bingo[i][j]==0) tate=0;
    }
    if(tate) ok=1;
  }
  rep(i,3){
    bool tate=1;
    rep(j,3){
      if(bingo[j][i]==0) tate=0;
    }
    if(tate) ok=1;
  }
  if(bingo[0][0]&&bingo[1][1]&&bingo[2][2]) ok=1;
  if(bingo[0][2]&&bingo[1][1]&&bingo[2][0]) ok=1;
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;

}