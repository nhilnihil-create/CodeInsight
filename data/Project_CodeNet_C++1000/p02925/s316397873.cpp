// *rbegin で配列外参照

#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

// pair 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const pair<T,S>& p){
  cout << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(){
  int n; cin >>n;
  vector<vector<int>> a(n);
  rep(i,n){
    rep(j,n-1){
      int v; cin >>v; v--;
      a[i].push_back(v);
    }
  }
  if(df)print("");
  if(df) rep(i,n) print(a[i]);
  int cnt=0,s=n*(n-1)/2;
  while(s>0){
    vector<pair<int,int>> siai;
    rep(i,n){
      if(a[i].size()==0) continue;
      int j=*a[i].rbegin();
      if(i>j) continue;
      if(i!=*a[j].rbegin()) continue;
      siai.push_back({i,j});
    }
    if(siai.size()==0){
      print(-1);
      if(df){
        rep(t,n)print(a[t]);
      }
      return 0;
    }
    if(df){
      print(siai);
    }
    s-=siai.size();
    if(df)print(s);
    for(auto p:siai){
      a[p.first].pop_back();
      a[p.second].pop_back();
    }
    cnt++;
  }
  print(cnt);
}
