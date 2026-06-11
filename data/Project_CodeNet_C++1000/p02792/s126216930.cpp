#include <iostream>
using namespace std;
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
long long keta(long long x){
  int y=0;
  while(x!=0){
    y++;
    x/=10;
  }
  return y;
}

int main(void){
    // Your code here!
  int n;
  cin >> n;
  int k=keta(n);
  ll ans=0;
  VVi v(10,vector<int>(10));
  rrep(i,1,10)rrep(j,1,10){
    rrep(l,1,k){
      int x=(n-i*pow(10,l)-j);
      if(x<=0) continue;
      x/=10;x++;
      int z=pow(10,l-1);
      int y=min(z,x);
      v[i][j]+=y;
    }
  }
  rrep(i,1,10){
    v[i][i]++;
  }
  rrep(i,1,10)rrep(j,1,10){
    ans+=v[i][j]*v[j][i];
  }
  if(n<=9) ans=n;
  cout << ans << endl;
  
    
}
