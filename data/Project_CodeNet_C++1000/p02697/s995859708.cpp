#include<iostream>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n,m; cin >>n >>m;
  int h=n%2?n:n/4;
  h=min(h,m);
  rep(i,h){
    print(i+1,n-i);
  }
  h=m-h;
  h=max(0,h);
  rep(i,h){
    print(n/2-i-1,n/2+i+1);
  }
}
