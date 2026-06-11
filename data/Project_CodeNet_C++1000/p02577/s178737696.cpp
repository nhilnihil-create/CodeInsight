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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar_unlocked();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
char S[200000+2];
int main(){
  int i;
  int res = 0;
  N = rd(S);
  for(i=(0);i<(N);i++){
    res += S[i] - '0';
  }
  if(res%9){
    wt_L("No");
    wt_L('\n');
  }
  else{
    wt_L("Yes");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200911-1

// --- original code ---
// int N;
// char S[2d5+2];
// {
//   int res = 0;
//   rd(S@N);
//   rep(i,N) res += S[i] - '0';
//   wt(if[res%9, "No", "Yes"]);
// }
