#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------


int main() {
  ll n,ans=1;
  cin>>n;
  
  vll a(n),b(n+1,0);
  b.at(0)=3;
  rep(i,n)cin>>a.at(i);
  
  rep(i,n){
      ans*=b.at(a.at(i));
      ans%=1000000007;

      b.at(a.at(i))--;
      b.at(a.at(i)+1)++;
  }
   
   
   cout<<ans<<endl;
}

