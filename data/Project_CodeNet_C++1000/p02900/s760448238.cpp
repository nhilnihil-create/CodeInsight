#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
//typedef pair<ll, ll> P;
const ll INF=1LL<<60;
//構造体（外側だけ）
struct Sieve{
  //素因数分解（素数、何個あるか）
  vector<pair<long long,int>>factor(long long x){
    vector<pair<long long,int>>res;
    for(long long i=2;i*i<=x;++i){
      int y=0;
      while(x%i==0){
        x/=i;
        ++y;
      }
      if(y!=0)res.emplace_back(x,y);
    }
    if(x!=1)res.emplace_back(x,1);
    return res;
  }
};
int gcd(int a, int b){
   if (a%b == 0)return(b);
   else return(gcd(b, a%b));
}
int main(){
  long long a,b;
  cin>>a>>b;
  ll n=gcd(a,b);
  Sieve s;
  auto fs=s.factor(n);
  int ans=fs.size()+1;
  cout<<ans<<endl;
  return 0;
}