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
int main(){
  int K, N;
  rd(N);
  rd(K);
  if(K==1){
    wt_L(0);
    wt_L('\n');
  }
  else{
    wt_L(N-K);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// {
//   int N, K;
//   rd(N, K);
//   wt(if[K==1,0,N-K]);
// }
