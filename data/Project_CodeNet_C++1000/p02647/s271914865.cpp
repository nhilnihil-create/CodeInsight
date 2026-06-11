#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define ceil(a,b) (((a)+(b)-1)/(b))
#define dist(a,b) max((a)-(b),(b)-(a))
#define yn(i) print((i)?"Yes":"No")
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
  int n,k; cin >>n >>k;
  vector<int> v(n); rep(i,n) cin >>v[i];
  int f=0;
  rep(i,k){
    if(f)break;
    vector<int> d(n,0);
    rep(j,n){
      int a,b;
      a=max(0,j-v[j]);
      b=j+v[j]+1;
      d[a]++;
      if(b<n)d[b]--;
    }
    int tmp=0;
    f=1;
    rep(j,n){
      tmp+=d[j];
      v[j]=tmp;
      if(v[j]!=n)f=0;
    }
    if(df)print(v);
  }
  print(v);
}



