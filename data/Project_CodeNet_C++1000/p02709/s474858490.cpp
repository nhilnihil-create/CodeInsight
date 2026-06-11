#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
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
inline void rd(long long &x){
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
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int ind[2000];
long long A[2000];
long long dp[2000];
long long nx[2000];
int main(){
  int i, k;
  wmem = memarr;
  int x;
  int y;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  rsortA_L(N, A, ind);
  for(k=(0);k<(N);k++){
    for(i=(0);i<(k+2);i++){
      nx[i] = -4611686016279904256LL;
    }
    for(i=(0);i<(k+1);i++){
      x = i;
      y = N - 1 - (k-i);
      chmax(nx[i+1], dp[i] + abs(ind[k]-x) * A[k]);
      chmax(nx[i], dp[i] + abs(ind[k]-y) * A[k]);
    }
    for(i=(0);i<(k+2);i++){
      dp[i] = nx[i];
    }
  }
  {
    int a2conNHc;
    long long hCmBdyQB;
    if(N+1==0){
      hCmBdyQB = 0;
    }
    else{
      hCmBdyQB = dp[0];
      for(a2conNHc=(1);a2conNHc<(N+1);a2conNHc++){
        hCmBdyQB = max_L(hCmBdyQB, dp[a2conNHc]);
      }
    }
    wt_L(hCmBdyQB);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200430-1

// --- original code ---
// int N, ind[2000];
// ll A[2000];
// ll dp[2000], nx[2000];
// {
//   int x, y;
//   rd(N,A(N));
//   rep(i,N) ind[i] = i;
//   rsortA(N, A, ind);
// 
//   rep(k,N){
//     rep(i,k+2) nx[i] = -ll_inf;
//     rep(i,k+1){
//       x = i;
//       y = N - 1 - (k-i);
//       nx[i+1] >?= dp[i] + abs(ind[k]-x) * A[k];
//       nx[i] >?= dp[i] + abs(ind[k]-y) * A[k];
//     }
//     rep(i,k+2) dp[i] = nx[i];
//   }
// 
//   wt(max(dp(N+1)));
// }
