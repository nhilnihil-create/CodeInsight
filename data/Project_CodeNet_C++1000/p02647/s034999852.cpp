#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#define rep(i,n) for(ll i=0;i<n;i++)
typedef long long ll;
using namespace std;

const ll MAX = 1000000;
const ll MOD = 1000000007;

ll fac[MAX];

// テーブルを作る前処理
/*
void COMinit() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
}
*/

ll pow_kai(ll a,ll n){//aのn乗を計算します。
  ll x = 1;
  while(n > 0){//全てのbitが捨てられるまで。
    if(n&1){//1番右のbitが1のとき。
      x = x*a%MOD;
    }
    a = a*a%MOD;
    n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
  }
  return x;
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    ll tmp=1;
    for(ll i=n;i>=n-k+1;i--) tmp = (tmp*i)%MOD;

    return (tmp * pow_kai(fac[k],MOD-2)) % MOD;
}

void chmax(ll &a,const ll &b){
    if(a<b) a=b;
}
void chmin(ll &a,const ll &b){
    if(a>b) a=b;
}


int main()
{

    ll N,K;
    cin >> N >>K;
    ll A[N],tmp[N];
    rep(i,N) {
        cin >> A[i];
        tmp[i]=A[i];
    }

    ll flg=0,kaisu=0,left,right,n1=0,n2=N-1,tot;

    while(flg!=N && kaisu<K){
        flg=0;
        tot=0;
        rep(i,N) tmp[i]=0;
        rep(i,N){
            left=max(n1,i-A[i]);
            right=min(n2,i+A[i]+1);
            tmp[left]++;
            if(i+A[i]+1<=n2) tmp[right]--;
        }
        rep(i,N){
            tot +=tmp[i];
            A[i]=tot;
            if(A[i]==N) flg++;
        }
        kaisu++;
    }


        rep(i,N-1){
            cout << A[i] <<" " ;
        }
        cout << A[N-1] << endl;



    return 0;


}