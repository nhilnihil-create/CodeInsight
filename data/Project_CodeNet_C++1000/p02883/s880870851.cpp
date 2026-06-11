#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

li judge(vector<li>& a,vector<li>& f,li m){
  int n=a.size();
  li s=0;
  rep(i,n){
    li d=a[i]-m/f[i];
    if(d>0) s+=d;
  }
  return s;
}

int main(){
  int n; li k; cin >>n >>k;
  vector<li> a(n),f(n);
  rep(i,n) cin >>a[i];
  rep(i,n) cin >>f[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  sort(f.begin(),f.end());
  li ok=a[0]*f[n-1]+1,ng=-1;
  while(ok-ng>1){
    li m=(ok+ng)/2;
    (judge(a,f,m)<=k?ok:ng)=m;
  }
  print(ok);
}
