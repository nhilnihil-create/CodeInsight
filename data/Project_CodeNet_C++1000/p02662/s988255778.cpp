#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long li;
#define MOD 998244353
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
struct modint{
  li num;

  modint(li a=0){
    num=(a%MOD+MOD)%MOD;
  }
  modint operator+(modint a) {return{(num+a.num)%MOD};} 
  modint operator-(modint a) {return{((num-a.num)%MOD+MOD)%MOD};}
  modint operator*(modint a) {return{num*a.num%MOD};}
  modint inv(modint a);
  modint operator/(modint a) {return {*this*inv(a)};}
  modint operator+=(modint a) {
    (num+=a.num)%=MOD;
    return *this;
  } 
  modint operator*=(modint a) {
    (num*=a.num)%=MOD;
    return *this;
  } 
};
modint inv(modint a){
    // unordered_map 必須 O(1)
    static unordered_map<li,modint> f;
    f[1]=1;
    if(f.find(a.num)!=f.end())return f[a.num];
    modint m=MOD%a.num;
    return f[a.num]=(modint)(MOD/a.num*(-1))*inv(m);
}

std::ostream& operator<<(std::ostream& os, const modint& m){
  // ここでストリームに obj を書き込みます。
  li a=m.num;
  a%=MOD;
  a+=MOD;
  a%=MOD;
  cout << a;
  return os;
}

std::istream& operator>>(std::istream& os,modint& m){
  // ここでストリームに obj を書き込みます。
  li a; cin >>a;
  m=a;
  return os;
}

int main(){
  int n,s; cin >>n >>s;
  vector<int> a(n); for(int& x:a) cin >>x;
  vector<modint> c(s+1);
  c[0]=1;
  rep(i,n){
    rep(_j,s+1){
      int j=s-_j;
      c[j]*=2;
      if(j-a[i]>=0) c[j]+=c[j-a[i]];
    }
    if(df)print(c);
  }
  print(c[s]);
}
