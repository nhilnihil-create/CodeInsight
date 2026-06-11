#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int K;
int D[5000];
int Q;
int N;
int X;
int M;
long long a[5000];
long long s;
int main(){
  int e98WHCEY;
  rd(K);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(K);Lj4PdHRW++){
      rd(D[Lj4PdHRW]);
    }
  }
  for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
    int i;
    rd(N);
    rd(X);
    rd(M);
    for(i=(0);i<(K);i++){
      if(D[i]%M==0){
        a[i] =M;
      }
      else{
        a[i] =D[i] % M;
      }
    }
    {
      int WYIGIcGE;
      long long t_ynMSdg;
      if(K==0){
        t_ynMSdg = 0;
      }
      else{
        t_ynMSdg = a[0];
        for(WYIGIcGE=(1);WYIGIcGE<(K);WYIGIcGE++){
          t_ynMSdg += a[WYIGIcGE];
        }
      }
      {
        int tU__gIr_;
        long long a2conNHc;
        if((N-1)%K==0){
          a2conNHc = 0;
        }
        else{
          a2conNHc = a[0];
          for(tU__gIr_=(1);tU__gIr_<((N-1)%K);tU__gIr_++){
            a2conNHc += a[tU__gIr_];
          }
        }
        s = X % M + (N-1) / K *t_ynMSdg+a2conNHc;
      }
    }
    wt_L(N - 1 - s / M);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// int K, D[5000], Q, N, X, M;
// 
// ll a[5000], s;
// {
//   rd(K,Q,D(K));
//   rep(Q){
//     rd(N,X,M);
//     rep(i,K) a[i] = if[D[i]%M==0, M, D[i] % M];
//     s = X % M + (N-1) / K * sum(a(K)) + sum(a((N-1)%K));
//     wt(N - 1 - s / M);
//   }
// }
