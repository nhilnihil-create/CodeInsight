#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long li;
#define MOD 1000000007
#define repa(i,a,n) for(int i=(a);i<(n);i++)
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

li totient(li n,vector<li>& factor){
  if(df)print("totient",n,":");
  for(li x:factor){
    n/=x;
    n*=x-1;
  }
  if(df)print(n);
  return n;
}

li pow(li a,li r){
  li b=a,s=1;
  if(df)print("pow",a,r);
  while(r){
    if(r%2) (s*=b)%=MOD;
    (b*=b)%=MOD;
    r/=2;
  }
  if(df)print(s);
  return s;
}

int main(){
  li n,k; cin >>k >>n;
  vector<vector<li>> factor(n+1);
  repa(i,2,n+1){
    if(factor[i].size())continue;
    repa(j,1,n+1){
      if(i*j>n)break;
      factor[i*j].push_back(i);
    }
  }
  if(df)rep(i,n+1)print(factor[i]);
  li s=0; 
  repa(i,1,n+1){
    s+=pow(n/i,k)*totient(i,factor[i])%MOD;
    s%=MOD;
  }
  print(s);
}
