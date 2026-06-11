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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
template<class T> inline T popFirst(multiset<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T popFirst(set<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
int N;
int z;
int num[1000000];
int now[1000000];
int sz;
int main(){
  int Lj4PdHRW;
  int i;
  int k;
  int c;
  multiset<int> s;
  multiset<int>::iterator it;
  rd(N);
  z = 1<<N;
  for(Lj4PdHRW=0;Lj4PdHRW<(z);Lj4PdHRW++){
    rd(k);
    s.insert(-k);
  }
  now[sz++] = popFirst(s);
  for(k=0;k<(N);k++){
    c = sz;
    for(i=0;i<(c);i++){
      it = s.upper_bound(now[i]);
      if(it==s.end()){
        wt_L("No");
        wt_L('\n');
        return 0;
      }
      now[sz++] = *it;
      s.erase(it);
    }
  }
  wt_L("Yes");
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// int N, z;
// int num[1d6];
// int now[1d6], sz;
// {
//   int i, k, c;
//   multiset<int> s;
//   multiset<int>::iterator it;
//   
//   rd(N);
//   z = 1<<N;
//   rep(z){
//     rd(k);
//     s.insert(-k);
//   }
// 
//   now[sz++] = popFirst(s);
//   rep(k,N){
//     c = sz;
//     rep(i,c){
//       it = s.upper_bound(now[i]);
//       if(it==s.end()) wt("No"), return 0;
//       now[sz++] = *it;
//       s.erase(it);
//     }
//   }
// 
//   wt("Yes");
// }
