#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;

int main() {
  ll N,K;cin>>N>>K;
  vector<ll>A(N);
  vector<ll>B(N);
  rep(i,N){
    cin>>A[i];
  }
  rep(i,N){
    cin>>B[i];
  }
  sort(B.begin(),B.end());
  sort(A.begin(),A.end());
  reverse(B.begin(),B.end());
  ll mi=0ll;
  ll ma=100000000000000ll;
  while(ma-mi>0){
    ll mid=(ma+mi)/2ll;
    ll sum=0ll;
    rep(i,N){
      ll g=mid/B[i];
      if(A[i]>g){sum+=(A[i]-g);}
    }
    if(sum<=K){ma=mid;}
    else{mi=mid+1;}
  }
  cout<<ma<<endl;
}

