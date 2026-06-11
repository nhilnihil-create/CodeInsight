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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
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
inline void rd(double &x){
  scanf("%lf",&x);
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(double x){
  printf("%.15f",x);
}
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
char memarr[96000000];
int N;
double X[200];
double Y[200];
double t[100];
int main(){
  double res=0, sx, sy;
  int i, j;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  for(i=0;i<(N);i++){
    t[i] = atan2(Y[i],X[i]);
  }
  sortA_L(N, t, X, Y);
  for(i=0;i<(N);i++){
    X[i+N] = X[i];
  }
  for(i=0;i<(N);i++){
    Y[i+N] = Y[i];
  }
  for(i=0;i<(N);i++){
    sx = sy = 0;
    for(j=0;j<(N);j++){
      sx += X[i+j];
      sy += Y[i+j];
      chmax(res,pow2_L(sx)+pow2_L(sy));
    }
  }
  res = sqrt(res);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N;
// double X[200], Y[200];
// double t[100];
// {
//   int i, j;
//   double sx, sy, res = 0;
//   
//   rd(N,(X,Y)(N));
//   rep(i,N) t[i] = atan2(Y[i],X[i]);
//   sortA(N, t, X, Y);
// 
//   rep(i,N) X[i+N] = X[i];
//   rep(i,N) Y[i+N] = Y[i];
// 
//   rep(i,N){
//     sx = sy = 0;
//     rep(j,N){
//       sx += X[i+j];
//       sy += Y[i+j];
//       res >?= sx**2 + sy**2;
//     }
//   }
// 
//   res = sqrt(res);
//   wt(res);
// }
