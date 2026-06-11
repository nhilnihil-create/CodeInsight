#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll digit(ll n){ll k=0; while(n!=0){n/=10; k++;} return k;}  

ll my_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main()
{
  ll N; cin>>N;
  
  if(N<10) {cout<<N<<endl; return 0;}
  
  vector<vector<ll>> table(10,vector<ll>(10,0));
  ll same_count=0;
  
  rep(i,N){
    ll n=i+1;
    table[n/my_pow(10,digit(n)-1)][n%10]++;
    if(n/my_pow(10,digit(n)-1)==n%10) same_count++;
  }
  
  ll ans=0;
  rep(i,10){
    rep(j,10){
      if(i==j) {ans+=table[i][i]*(table[i][i]-1); continue;}
      ans+=table[i][j]*table[j][i];
      //cout<<i<<" "<<j<<" "<<ans<<endl;
    }
  }
  ans+=same_count;
  
  cout<<ans<<endl;
  
  //cout<<same_count<<endl;
  /*
  rep(i,10){
    rep(j,10){
      if(j!=0) cout<<" ";
      cout<<table[i][j];
    }
    cout<<endl;
  }
  */
  return 0;
}