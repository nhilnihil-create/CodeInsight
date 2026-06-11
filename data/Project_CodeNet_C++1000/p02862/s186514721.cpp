#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

const int MAX = 1000005;

long long fac[MAX], finv[MAX], inv[MAX]; //n!, 1/n!, 1/n

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int x,y,a,b;
  cin >> x >> y;
  if((x+y)%3 !=0 || ((x+y)/3+x-y)%2!=0 || ((x+y)/3+y-x)%2!=0){
    cout << 0 << endl;
    return 0;
  }
  a = ((x+y)/3+x-y)/2;
  b = ((x+y)/3-x+y)/2;
  COMinit();
  cout << COM(a+b,a) << endl;

  return 0;
}
