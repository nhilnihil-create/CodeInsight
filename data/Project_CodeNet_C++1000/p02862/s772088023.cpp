#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX = 2000010;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
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
  ll c=0,d=0,x,y,z;
  scanf("%lld %lld\n",&x,&y);
  COMinit();
  if((x%3==0 && y%3==0)||(x%3==1 && y%3==2)||(x%3==2 && y%3==1)){
    z=x-y;
    if(z>0){
      d=z;
      c+=(y-d)/3;
      d+=(y-d)/3;
    }
    else{
      z=abs(z);
      c=z;
      d+=(x-c)/3;
      c+=(x-c)/3;
    }
    if(c<0 || d<0){
      printf("0\n");
      return 0;
    }
    printf("%lld\n",COM(c+d,c));
  }
  else{
    printf("0\n");
    return 0;
  }
  return 0;
}