#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar_unlocked(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread_unlocked(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar_unlocked();
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
    k = my_getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar_unlocked(c[i]);
  }
}
int N;
int D[100][2];
int ok[100];
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(2);KL2GvlyY++){
        rd(D[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(D[i][0]==D[i][1]){
      ok[i] =1;
    }
    else{
      ok[i] =0;
    }
  }
  for(i=(2);i<(N);i++){
    if(ok[i-2] && ok[i-1] && ok[i]){
      wt_L("Yes");
      wt_L('\n');
      return 0;
    }
  }
  wt_L("No");
  wt_L('\n');
  return 0;
}
// cLay varsion 20200916-1

// --- original code ---
// int N, D[100][2];
// int ok[100];
// {
//   rd(N,D(N,2));
//   rep(i,N) ok[i] = if[D[i][0]==D[i][1], 1, 0];
//   rep(i,2,N) if(ok[i-2] && ok[i-1] && ok[i]) wt("Yes"), return 0;
//   wt("No");
// }
