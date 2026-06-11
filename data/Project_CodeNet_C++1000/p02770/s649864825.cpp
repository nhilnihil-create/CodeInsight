#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K,Q;
  cin>>K>>Q;
  vector<ll> D(K);
  rep(i,K) cin>>D[i];

  for(int q=0;q<Q;q++){
      ll N,X,M;
      cin>>N>>X>>M;
      N--;
      X%=M;

      vector<ll> A=D;
      rep(i,K) A[i]%=M;
      ll sum=0;
      rep(i,K) sum+=A[i];

      ll last=X+sum*(N/K);
      rep(i,N%K) last+=A[i];

      ll ng=(last/M)-(X/M);
      ll keep=0;
      rep(i,K) if(A[i]==0) keep++;
      keep*=(N/K);
      rep(i,N%K) if(A[i]==0) keep++;

      ll ans=N;
      ans-=keep;
      ans-=ng;
      cout<<ans<<endl;
  }

  return 0;
}
