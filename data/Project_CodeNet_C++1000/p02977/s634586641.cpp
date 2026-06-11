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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int N;
int M;
int A[200000];
int B[200000];
void doit(int a, int b){
  A[M] = a;
  B[M++] = b;
}
int main(){
  int i, k;
  rd(N);
  k = 0;
  for(i=0;i<20;i++){
    if(N&1<<i){
      k = (1<<i);
    }
  }
  if(N==k){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  doit(1, 2);
  doit(2, 3);
  doit(3, 1+N);
  doit(1+N, 2+N);
  doit(2+N, 3+N);
  for(i=4;i<N;i+=2){
    doit(i, i+1);
    doit(N+i, N+i+1);
    doit(1, i);
    doit(1, N+i+1);
  }
  if(N%2==0){
    doit(k+1+N, N);
    doit(N-k, N+N);
  }
  wt_L("Yes");
  wt_L('\n');
  for(i=0;i<M;i++){
    wt_L(A[i]);
    wt_L(' ');
    wt_L(B[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190714-1

// --- original code ---
// int N;
// 
// int M, A[2d5], B[2d5];
// 
// void doit(int a, int b){
//   A[M] = a;
//   B[M++] = b;
// }
// 
// {
//   int i, k;
// 
//   rd(N);
// 
//   k = 0;
//   rep(i,20) if(N&1<<i) k = (1<<i);
// 
//   if(N==k){
//     wt("No");
//     return 0;
//   }
// 
//   doit(1, 2);
//   doit(2, 3);
//   doit(3, 1+N);
//   doit(1+N, 2+N);
//   doit(2+N, 3+N);
// 
//   for(i=4;i<N;i+=2){
//     doit(i, i+1);
//     doit(N+i, N+i+1);
//     doit(1, i);
//     doit(1, N+i+1);
//   }
//   if(N%2==0){
//     doit(k+1+N, N);
//     doit(N-k, N+N);
//   }
// 
//   wt("Yes");
//   rep(i,M) wt(A[i], B[i]);
// }
