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
int N;
int A[100000];
int res;
int ress;
int resx[100000];
int resy[100000];
inline int doit(int x, int y){
  resx[ress] = x;
  resy[ress++] = y;
  return x - y;
}
int main(){
  int i, j, k, mi, mx;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY, Q5VJL1cS=0, RZTsC2BF, cTE1_r3A, e98WHCEY;
    for(KL2GvlyY=(0);KL2GvlyY<((N-1)+1);KL2GvlyY++){
      cTE1_r3A = A[KL2GvlyY];
      if(Q5VJL1cS==0 || e98WHCEY>cTE1_r3A){
        e98WHCEY = cTE1_r3A;
        Q5VJL1cS = 1;
        RZTsC2BF = KL2GvlyY;
      }
    }
    mi =RZTsC2BF;
  }
  {
    int FmcKpFmN, KrdatlYV, WYIGIcGE, t_ynMSdg, xr20shxY=0;
    for(FmcKpFmN=(0);FmcKpFmN<((N-1)+1);FmcKpFmN++){
      t_ynMSdg = A[FmcKpFmN];
      if(xr20shxY==0 || WYIGIcGE<t_ynMSdg){
        WYIGIcGE = t_ynMSdg;
        xr20shxY = 1;
        KrdatlYV = FmcKpFmN;
      }
    }
    mx =KrdatlYV;
  }
  if(mi==mx){
    mx++;
  }
  for(i=0;i<(N);i++){
    if(i==mi || i==mx){
      continue;
    }
    if(A[i] >= 0){
      A[mi] = doit(A[mi], A[i]);
    }
    else{
      A[mx] = doit(A[mx], A[i]);
    }
  }
  res = doit(A[mx], A[mi]);
  wt_L(res);
  wt_L('\n');
  for(i=0;i<(ress);i++){
    wt_L(resx[i]);
    wt_L(' ');
    wt_L(resy[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N, A[1d5];
// 
// int res, ress, resx[1d5], resy[1d5];
// 
// inline int doit(int x, int y){
//   resx[ress] = x;
//   resy[ress++] = y;
//   return x - y;
// }
// 
// {
//   int i, j, k, mi, mx;
//   rd(N,A(N));
// 
//   mi = argmin[k=0---N-1](A[k]);
//   mx = argmax[k=0---N-1](A[k]);
//   if(mi==mx) mx++;
// 
//   rep(i,N){
//     if(i==mi || i==mx) continue;
//     if(A[i] >= 0) A[mi] = doit(A[mi], A[i]);
//     else          A[mx] = doit(A[mx], A[i]);
//   }
//   res = doit(A[mx], A[mi]);
// 
//   wt(res);
//   rep(i,ress) wt(resx[i], resy[i]);
// }
