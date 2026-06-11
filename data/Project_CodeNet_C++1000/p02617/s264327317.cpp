#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }


int main(){
  li n;cin >>n;
  li s=0;
  rep(i,n){
    s+=(i+1)*(n-i);
  }
  if(df)print(s);
  
  li mn=0;
  rep(i,n-1){
    int u,v; cin >>u >>v;
    if(u>v)swap(u,v);
    mn+=u*(n-v+1);
  }
  print(s-mn);
  if(s-mn<0){
    while(1) print(1);
  }
}
