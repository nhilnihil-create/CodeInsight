// 最大公約数
// a,bの最小公倍数(LCM)はa*b/GCD
/*
 * C言語のサンプルプログラム - Webkaru
 * - 入力した2つの自然数の最大公約数を求める -
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


ll gcd(ll a, ll b)
{

    ll r, tmp;
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }

  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  return b;
}

int main(){
    int a,b;
    cin>>a>>b;
    ll lcm=(ll)a*b/gcd(a,b);
    cout<<lcm<<endl;
}