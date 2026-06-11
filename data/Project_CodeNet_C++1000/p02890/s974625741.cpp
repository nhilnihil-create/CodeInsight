#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
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
template<class T> int runLength(int N, T *arr, T *val = NULL, int *len = NULL){
  int i;
  int rN;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void *mem = wmem;
    walloc1d(&val, N, &mem);
    walloc1d(&len, N, &mem);
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[300000];
int arr[300000];
int res[300000];
int sz;
int num[300000];
int len[300000];
int main(){
  int i;
  wmem = memarr;
  int k;
  int x;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    arr[A[i]]++;
  }
  rsortA_L(N,arr);
  sz = runLength(N, arr, num, len);
  for(i=(N)-1;i>=(0);i--){
    k = res[i] = num[sz-1];
    len[sz-1]--;
    if(len[sz-1]==0){
      sz--;
    }
    if(i==0){
      break;
    }
    while(k > 0){
      x = k / len[sz-1];
      if(sz>=2){
        chmin(x, num[sz-2] - num[sz-1]);
      }
      if(x || (sz>=2 && num[sz-2]==num[sz-1])){
        k -= len[sz-1] * x;
        num[sz-1] += x;
        if(sz>=2 && num[sz-2] == num[sz-1]){
          len[sz-2] += len[sz-1];
          sz--;
        }
      }
      else{
        num[sz] = num[sz-1];
        len[sz] = len[sz-1] - k;
        num[sz-1]++;
        len[sz-1] = k;
        k = 0;
        sz++;
      }
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(N);KL2GvlyY++){
      wt_L(res[KL2GvlyY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// int N, A[3d5];
// int arr[3d5], res[3d5];
// int sz, num[3d5], len[3d5];
// {
//   int k, x;
//   rd(N,(A--)(N));
//   rep(i,N) arr[A[i]]++;
//   rsortA(N,arr);
// 
//   sz = runLength(N, arr, num, len);
//   rrep(i,N){
//     k = res[i] = num[sz-1];
//     len[sz-1]--;
//     if(len[sz-1]==0) sz--;
//     if(i==0) break;
//     while(k > 0){
//       x = k / len[sz-1];
//       if(sz>=2) x <?= num[sz-2] - num[sz-1];
//       if(x || (sz>=2 && num[sz-2]==num[sz-1])){
//         k -= len[sz-1] * x;
//         num[sz-1] += x;
//         if(sz>=2 && num[sz-2] == num[sz-1]){
//           len[sz-2] += len[sz-1];
//           sz--;
//         }
//       } else {
//         num[sz] = num[sz-1];
//         len[sz] = len[sz-1] - k;
//         num[sz-1]++;
//         len[sz-1] = k;
//         k = 0;
//         sz++;
//       }
//     }
//   }
//   wtLn(res(N));
// }
