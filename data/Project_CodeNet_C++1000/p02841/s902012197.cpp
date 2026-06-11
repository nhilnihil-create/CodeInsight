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
int M1;
int D1;
int M2;
int D2;
int main(){
  rd(M1);
  rd(D1);
  rd(M2);
  rd(D2);
  if(M1!=M2){
    wt_L(1);
    wt_L('\n');
  }
  else{
    wt_L(0);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// int M1, D1, M2, D2;
// {
//   rd(M1,D1,M2,D2);
//   wt(if[M1!=M2, 1, 0]);
// }
