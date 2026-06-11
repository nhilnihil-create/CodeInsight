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
  vector<ll> A(N+1); rep(i,N+1) cin>>A[i];
  
  //上から抑える
  vector<ll> msum(N+1,1);
  if(msum[0]-A[0]<0) {cout<<-1<<endl; return 0;}
  rep(i,N){
    msum[i+1]=min(INF,(msum[i]-A[i])*2);
    if(msum[i+1]-A[i+1]<0) {cout<<-1<<endl; return 0;}
  }
  
  //下から抑える
  ll sum=0,ans=0;
  for(int i=N;i>=0;i--){
    sum=min(sum+A[i],msum[i]);
    ans+=sum;
  }
  cout<<ans<<endl;
  return 0;
}
