#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
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
  li n,a,b; cin >>n >>a >>b;
  if(((b^a)&1)==0){
    print(dist(a,b)/2);
  }else{
    li x=a+b-1,y=n-a+n-b+1;
    if(x>y)swap(x,y);
    print(x/2);
  }
}



