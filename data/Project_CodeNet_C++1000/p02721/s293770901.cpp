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

int main(){
  int n,k,c; cin >>n >>k >>c;
  string s; cin >>s;
  vector<int> v(n,0);
  int cnt=k;
  rep(_i,n){
    int i=n-1-_i;
    if(df)print(s[i]);
    if(s[i]=='o'){
      v[i]=cnt;
      cnt--;
      _i+=c;
    }
  }
  if(df)print(v);
  vector<int> ans;
  cnt=0;
  rep(i,n){
    if(s[i]=='o'){
      cnt++;
      if(v[i]==cnt) ans.push_back(i+1);
      i+=c;
    }
  }
  for(int x:ans) print(x);
}
