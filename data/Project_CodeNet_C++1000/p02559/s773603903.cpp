#include<iostream>
#include<atcoder/all>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n,q; cin >>n >>q;
  atcoder::fenwick_tree<li> bit(n);
  rep(i,n){
    li a; cin >>a;
    bit.add(i,a);
  }
  rep(_,q){
    li t,p,x; cin >>t >>p >>x;
    if(t==0) bit.add(p,x);
    else{
      print(bit.sum(p,x));
    }
  }
}
