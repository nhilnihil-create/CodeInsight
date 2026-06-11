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
inline void rd(long long &x){
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
int N;
long long A[100000];
int ok[60];
int main(){
  int i;
  int j;
  int k;
  long long res = 0;
  long long s = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=0;i<(N);i++){
    s ^= A[i];
  }
  for(i=0;i<(60);i++){
    if(s & (1LL<<i)){
      res += (1LL<<i);
      for(j=0;j<(N);j++){
        if(A[j] & (1LL<<i)){
          A[j] ^= (1LL<<i);
        }
      }
    }
  }
  k = 0;
  for(i=59; i>=0; i--){
    for(j=(k);j<(N);j++){
      if(A[j] & (1LL<<i)){
        break;
      }
    }
    if(j==N){
      continue;
    }
    if(j!=k){
      swap(A[k], A[j]);
    }
    for(j=(k+1);j<(N);j++){
      if(A[j] & (1LL<<i)){
        A[j] ^= A[k];
      }
    }
    k++;
    if(k >= N){
      break;
    }
  }
  s = 0;
  for(i=0;i<(N);i++){
    if(s < (s^A[i])){
      s ^= A[i];
    }
  }
  res += 2*s;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// int N;
// ll A[1d5];
// int ok[60];
// {
//   int i, j, k;
//   ll res = 0, s = 0;
//   
//   rd(N,A(N));
//   rep(i,N) s ^= A[i];
// 
//   rep(i,60) if(s & (1LL<<i)){
//     res += (1LL<<i);
//     rep(j,N) if(A[j] & (1LL<<i)) A[j] ^= (1LL<<i);
//   }
// 
//   k = 0;
//   for(i=59; i>=0; i--){
//     rep(j,k,N) if(A[j] & (1LL<<i)) break;
//     if(j==N) continue;
//     if(j!=k) swap(A[k], A[j]);
//     rep(j,k+1,N) if(A[j] & (1LL<<i)) A[j] ^= A[k];
//     k++;
//     if(k >= N) break;
//   }
// 
//   s = 0;
//   rep(i,N) if(s < (s^A[i])) s ^= A[i];
//   res += 2s;
// 
//   wt(res);
// }
