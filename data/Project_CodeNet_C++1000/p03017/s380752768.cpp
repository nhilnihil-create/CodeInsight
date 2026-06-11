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
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  A--;B--;C--;D--;
  vector<char> S(N);
  rep(i,N) cin >> S[i];
  bool e=true;
  rep2(i,A,max(C,D)){
    if (S[i+1]=='#'&&S[i]=='#') {
      e = false; break;
    }
  }

  bool f=false;
  if (C>D) rep2(i,B-1,min(C,D)){
    if (S[i]=='.' && S[i+1]=='.' && S[i+2]=='.') {
      f = true; break;
    }
  }
  if (e&&(C<D||f)) cout << "Yes\n";
  else cout << "No\n";
  
  return 0;
}