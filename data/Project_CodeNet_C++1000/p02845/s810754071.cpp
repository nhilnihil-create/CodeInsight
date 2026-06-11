#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
//using namespace atcoder;
typedef long long ll;
const ll mod = 1000000007;
int main(){
  ll N,i,a,ans = 1;scanf("%lld",&N);
  ll C[3] = {};
  for(i=0;i<N;i++){
    scanf("%lld",&a);
    ans = ans*(ll(C[0]==a)+(C[1]==a)+(C[2]==a))%mod;
    if(C[0] == a) C[0]++;
    else if(C[1] == a) C[1]++;
    else if(C[2] == a) C[2]++;
    else{
      printf("0\n");return 0;
    }
  }
  printf("%lld\n",ans);
}