#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define minimize(a,b) (a>(b)?a=(b),1:0)
#define maximize(a,b) (a<(b)?a=(b),1:0)
#define ceil(a,b) (((a)+(b)-1)/(b))
#define yn(i) print((i)?"Yes":"No")
#define chmin(a,b) (a>(b)?a=(b),1:0)
#define abs(n) max((n),-(n))
#define dist(a,b) max((a)-(b),(b)-(a))
#define chmax(a,b) (a<(b)?a=(b),1:0)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define MOD 1000000007
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
  string s,t; cin >>s;
  t=s;
  reverse(s.begin(),s.end());
  int n=s.size();
  int cnt=0;
  rep(i,n){
    if(s[i]!=t[i]) cnt++;
  }
  print(cnt/2);
}



