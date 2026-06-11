#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int main(){
  long long T1;
  long long T2;
  long long A1;
  long long A2;
  long long B1;
  long long B2;
  long long x1;
  long long x2;
  long long y1;
  long long y2;
  long long res;
  rd(T1);
  rd(T2);
  rd(A1);
  rd(A2);
  rd(B1);
  rd(B2);
  x1 = T1 * A1;
  x2 = x1 + T2 * A2;
  y1 = T1 * B1;
  y2 = y1 + T2 * B2;
  if(x1 == y1 || x2 == y2){
    wt_L("infinity");
    wt_L('\n');
    return 0;
  }
  if(x2 > y2){
    swap(x1,y1);
    swap(x2,y2);
  }
  if(y1 > x1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  res = (x1-y1)/(y2-x2) * 2 + 1;
  if((x1-y1)%(y2-x2) == 0){
    res--;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// {
//   ll T1, T2, A1, A2, B1, B2;
//   ll x1, x2, y1, y2;
//   ll res;
//   rd(T1,T2,A1,A2,B1,B2);
//   x1 = T1 * A1; x2 = x1 + T2 * A2;
//   y1 = T1 * B1; y2 = y1 + T2 * B2;
// 
//   if(x1 == y1 || x2 == y2) wt("infinity"), return 0;
//   if(x2 > y2){
//     swap(x1,y1);
//     swap(x2,y2);
//   }
//   if(y1 > x1) wt(0), return 0;
// 
//   res = (x1-y1)/(y2-x2) * 2 + 1;
//   if((x1-y1)%(y2-x2) == 0) res--;
//   wt(res);
// }
