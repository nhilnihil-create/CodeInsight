#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}



int main() {
  ll N,A,B,res;
  cin >> N >> A >> B;
  if (abs(A-B)%2==0) res=abs(A-B)/2;
  else {
    ll t1,t2;
    t1 = (max(A,B)-min(A,B))/2+min(A,B);
    t2 = ((N-min(A,B))-(N-max(A,B)+1))/2+N-max(A,B)+1;
    res = min(t1,t2);
  }
  cout << res << endl;
}