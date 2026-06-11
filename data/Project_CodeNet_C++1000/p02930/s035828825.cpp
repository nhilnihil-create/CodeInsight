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
inline int BIT_ctz_L(const int x){
  return __builtin_ctz(x);
}
inline int BIT_ctz_L(const long long x){
  return __builtin_ctzll(x);
}
int N;
int res[500];
int main(){
  int i;
  rd(N);
  for(i=(0);i<(N-1);i++){
    res[i] = 1 +BIT_ctz_L(i+1);
  }
  for(i=(0);i<(N-1);i++){
    {
      int Lj4PdHRW;
      if(N-1-i==0){
        putchar_unlocked('\n');
      }
      else{
        for(Lj4PdHRW=(0);Lj4PdHRW<(N-1-i-1);Lj4PdHRW++){
          wt_L(res[Lj4PdHRW]);
          wt_L(' ');
        }
        wt_L(res[Lj4PdHRW]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// int N;
// int res[500];
// {
//   rd(N);
//   rep(i,N-1) res[i] = 1 + BIT_ctz(i+1);
//   rep(i,N-1) wt(res(N-1-i));
// }
