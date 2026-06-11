#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const ll INF=1e9;
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};

ll intpow(ll n, int m){
  ll out=1;
  rep(i,m){
    out *=n;
  }
  return out;
}



int main(){
  ll n;
  cin>>n;
  if(n%2==1){//奇数の場合
    cout<<0<<endl;
    return 0;
  }
  ll ans=0;
  //偶数の場合
  //桁数計算


  // 5,5^2,5^3で割り切れる者の個数=2*5,2*5^2,2*5^3;
  rep1(m,26){
    //cout<<2*intpow(5,m)<<endl;
    ans +=n/(2*intpow(5,m));
  }
  cout<<ans<<endl;











}
