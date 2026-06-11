#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const lint MOD =1000000007;
const lint MAX = 10000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;

 
lint fac[MAX], finv[MAX], inv[MAX];

void COMinit() // 二項係数を求める時は前処理としてCOMinit()をする
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return 0;
        }
    }

    // 素数である
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

    //A1+B1とA2+B2の和が等しいときはinfA1,A2がそれぞれB1,B2より大きいまたその逆の時は必ずどっちかが先行し続けるため0;abs(A1-B1)>abs(A2-B2)のときは先に追い抜くより多く先行してしまうため０
   // それ以外では一回ごとにdif離れるのでdif/dif1の切り上げ*2-1;dif1%dif=0のときは最後に交わるため一足す
  int main(){
      lint T1,T2,A1,A2,B1,B2;
      cin>>T1>>T2>>A1>>A2>>B1>>B2;
      A1*=T1;
      B1*=T1;
      A2*=T2;
      B2*=T2;
      lint g=0;
    lint dif=abs(A1+A2-B1-B2);
    lint dif1=abs(A1-B1);
    if(dif!=0){
    if(dif1%dif==0)g++;
    }
      if(dif==0)cout<<"infinity";
      else if(A1>B1&&A2>B2)cout<<0;
      else if(A1<B1&&A2<B2)cout<<0;
      else if(abs(A1-B1)>abs(A2-B2))cout<<0;
      else cout<<(lint)((dif1+dif-1)/dif)*2-1+g;

    }
     
  
