#include<iostream>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  li n,k; cin >>n >>k;
  li l=(n-1)*(n-2)/2;
  if(k>l){
    print(-1);
    return 0;
  }
  print(n-1+l-k);
  rep(i,n-1){
    print(i+1,n);
  }
  int i=1,j=i+1;
  rep(_,l-k){
    print(i,j);
    j++;
    if(j>=n){
      i++;
      j=i+1;
    }
  }
}
