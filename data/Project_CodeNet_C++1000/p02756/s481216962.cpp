#include<iostream>
#include<list>
#include<algorithm>
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
    if(itr!=v.begin())cout << "";
    cout << *(itr++);
  }
  return os;
}

int main(){
  string s; cin >>s;
  int n=s.size();
  list<char> v;
  rep(i,n) v.push_back(s[i]);
  int q; cin >>q;
  int f=0;
  rep(_,q){
    int a; cin >>a;
    if(a==1){
      f^=1;
    }else{
      int b; cin >>b; b--;
      char c; cin >>c;
      if(f^b){
        v.push_back(c);
      }else{
        v.push_front(c);
      }
    }
  }
  if(f) reverse(v.begin(),v.end());
  print(v);
}
