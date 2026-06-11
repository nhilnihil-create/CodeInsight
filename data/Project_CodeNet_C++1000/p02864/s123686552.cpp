#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
int H[300];
long long dp[300][300];
long long nx[300][300];
int main(){
  int m;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(H[Lj4PdHRW]);
    }
  }
  if(N==K){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  for(m=(0);m<(N);m++){
    int i;
    for(i=(0);i<(K+1);i++){
      int j;
      for(j=(0);j<(m+1);j++){
        nx[i][j] = 4611686016279904256LL;
      }
    }
    if(m<=K){
      nx[m][m] = H[m];
    }
    for(i=(0);i<(K+1);i++){
      int j;
      for(j=(0);j<(m);j++){
        chmin(nx[i][m], dp[i][j] +max_L(H[m] - H[j], 0));
      }
    }
    for(i=(0);i<(K);i++){
      int j;
      for(j=(0);j<(m);j++){
        chmin(nx[i+1][j], dp[i][j]);
      }
    }
    for(i=(0);i<(K+1);i++){
      int j;
      for(j=(0);j<(m+1);j++){
        dp[i][j] = nx[i][j];
      }
    }
  }
  {
    int AlM5nNnR;
    long long XJIcIBrW;
    if(N==0){
      XJIcIBrW = 0;
    }
    else{
      XJIcIBrW = dp[K][0];
      for(AlM5nNnR=(1);AlM5nNnR<(N);AlM5nNnR++){
        XJIcIBrW = min_L(XJIcIBrW, dp[K][AlM5nNnR]);
      }
    }
    wt_L(XJIcIBrW);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// int N, K, H[300];
// ll dp[300][300], nx[300][300];
// 
// {
//   rd(N,K,H(N));
//   if(N==K) wt(0), return 0;
//   rep(m,N){
//     rep(i,K+1) rep(j,m+1) nx[i][j] = ll_inf;
//     if(m<=K) nx[m][m] = H[m];
//     rep(i,K+1) rep(j,m) nx[i][m] <?= dp[i][j] + max(H[m] - H[j], 0);
//     rep(i,K) rep(j,m) nx[i+1][j] <?= dp[i][j];
//     rep(i,K+1) rep(j,m+1) dp[i][j] = nx[i][j];
//   }
//   wt(min(dp[K](N)));
// }
