#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
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
inline void wt_L(long long x){
  char f[20];
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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template <class T> struct LHeap{
  T *val;
  int *hp, *place, size;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(val);
  }
  void init(int N){
    int i;
    size=0;
    for(i=0;i<(N);i++){
      place[i]=-1;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    T f=val[n];
    val[n] = v;
    if(place[n]==-1){
      place[n] = size;
      hp[size++] = n;
      up(place[n]);
    }
    else{
      if(f < v){
        down(place[n]);
      }
      else if(f > v){
        up(place[n]);
      }
    }
  }
  int pop(void){
    int res=hp[0];
    place[res] = -1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    return res;
  }
}
;
char memarr[96000000];
int N;
int A[200000];
int B[200000];
int main(){
  LHeap<int> hp;
  int i, j, mx, s;
  long long res=0;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
      rd(B[KL2GvlyY]);
    }
  }
  hp.walloc(N);
  hp.init(N);
  for(i=0;i<(N);i++){
    hp.change(i, -B[i]);
  }
  while(hp.size){
    i = hp.pop();
    if(A[i]==B[i]){
      continue;
    }
    if(A[i] > B[i]){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    s = B[(i+1)%N] + B[moddw_L((i-1),N)];
    mx = (B[i] - A[i]) / s;
    if(mx==0){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    res += mx;
    B[i] -= s * mx;
    hp.change(i, -B[i]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N, A[2d5], B[2d5];
// {
//   int i, j, s, mx;
//   ll res = 0;
//   LHeap<int> hp;
//   
//   rd(N,A(N),B(N));
// 
//   hp.walloc(N);
//   hp.init(N);
//   rep(i,N) hp.change(i, -B[i]);
// 
//   while(hp.size){
//     i = hp.pop();
//     if(A[i]==B[i]) continue;
//     if(A[i] > B[i]){ wt(-1); return 0; }
// 
//     s = B[(i+1)%N] + B[(i-1)%%N];
//     mx = (B[i] - A[i]) / s;
//     if(mx==0){ wt(-1); return 0; }
// 
//     res += mx;
//     B[i] -= s * mx;
//     hp.change(i, -B[i]);
//   }
// 
//   wt(res);
// }
