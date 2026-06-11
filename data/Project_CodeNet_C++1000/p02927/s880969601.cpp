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
int main(){
  int M;
  int D;
  int i;
  int j;
  int k;
  int res = 0;
  rd(M);
  rd(D);
  for(i=(1);i<(D+1);i++){
    j = i / 10;
    k = i % 10;
    if(j >= 2 && k >= 2 && j*k <= M){
      res++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// {
//   int M, D;
//   int i, j, k, res = 0;
//   rd(M, D);
//   rep(i,1,D+1){
//     j = i / 10;
//     k = i % 10;
//     if(j >= 2 && k >= 2 && j*k <= M) res++;
//   }
//   wt(res);
// }
