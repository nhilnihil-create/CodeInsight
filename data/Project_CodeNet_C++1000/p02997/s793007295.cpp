#include<iostream>
#include<cmath>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int findy(int k){
  return (1+sqrt(1+8*k))/2;
}
int findx(int k,int y){
  return k-y*(y-1)/2;
}

int main(){
  int n,k; cin >>n >>k;
  int cnt=(n-1)*(n-2)/2-k;
  if(cnt<0){
    print("-1");
    return 0;
  } 
  print(n+cnt-1);
  rep(i,n-1){
    print(i+1,n);
  }
  int i=0;
  while(cnt--){
    int y=findy(cnt),x=findx(cnt,y);
    print(x+1,y+1);
  }
}
