#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k, m=0;
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
inline void rd(long long &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
long long X[50];
long long Y[50];
int main(){
  int a, b, i, j, k, res, tmp;
  long long p, q;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  res = N;
  for(a=0;a<(N);a++){
    for(b=(a+1);b<(N);b++){
      p = X[b] - X[a];
      q = Y[b] - Y[a];
      tmp = N;
      for(i=0;i<(N);i++){
        for(j=0;j<(N);j++){
          if(X[j]-X[i]==p && Y[j]-Y[i]==q){
            tmp--;
          }
        }
      }
      chmin(res, tmp);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N;
// ll X[50], Y[50];
// {
//   int i, j, k, a, b;
//   int res, tmp;
//   ll p, q;
// 
//   rd(N,(X,Y)(N));
//   res = N;
// 
//   rep(a,N) rep(b,a+1,N){
//     p = X[b] - X[a];
//     q = Y[b] - Y[a];
// 
//     tmp = N;
//     rep(i,N) rep(j,N) if(X[j]-X[i]==p && Y[j]-Y[i]==q) tmp--;
//     res <?= tmp;
//   }
// 
//   wt(res);
// }
