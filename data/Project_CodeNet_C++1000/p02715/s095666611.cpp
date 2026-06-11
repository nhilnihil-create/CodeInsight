#include<iostream>
#include<vector>
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
  // ここでストリームに obj を書き込みます。
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

li pow(li a,int n){
  li ans=1;
  while(n){
    if(n%2) {
      ans*=a;
      if(df)print("*",a,ans);
      ans%=MOD;
    }
    (a*=a)%=MOD;
    n/=2;
  }
  return ans;
}


int main(){
  int n,k; cin >>n >>k;
  vector<li> v(k+1);
  rep(i,k+1) v[i]=i;

  auto f=
    [&](int a){
      int s=a*2;
      while(s<=k){
        v[s]-=v[a];
        s+=a;
      }
    };

  if(df)print(pow(10,10));

  li ans=0;
  repa(i,1,k+1){
    (ans+=pow(k/i,n)*v[i]%MOD)%=MOD;
    f(i);
  }
  if(df)print(v);
  print(ans);
}
