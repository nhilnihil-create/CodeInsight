#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


void solve(long long N, std::vector<long long> A){
  ll mask = 0; // 奇数個のビットが立ってる桁のマスク
  for(ll i=0; i<N; i++){
    mask ^= A[i];
  }

  // 偶数個のビットが立ってる桁だけに着目する。
  for(ll i=0; i<N; i++){
    A[i] = A[i] & (~mask);
  }

  ll n=0;
  for(ll m=1ll<<60; m; m>>=1){
    // 立ってるビットを見つける
    ll j;
    for(j=n; j<N; j++){
      if(A[j] & m){ break; }
    }
    if(j==N) continue;
    // ビットが立ってるやつを最初に持ってくる
    swap(A[n], A[j]);

    // 掃き出す。
    for(ll k=0; k<N; k++){
      if(k != n){
        if(A[k] & m){
          A[k] ^= A[n];
        }
      }
    }
    n++;
  }

  // 計算
  ll rst = 0;
  for(ll i=0; i<N; i++){
    rst ^= A[i];
  }
  cout << (rst + rst + mask) << endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
