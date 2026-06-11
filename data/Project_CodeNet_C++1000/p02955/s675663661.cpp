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
  ll N,K;
  cin>>N>>K;
  vector<ll>A(N);
  ll sum=0ll;
  rep(i,N){cin>>A[i];sum+=A[i];}
  ll n=sum;
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  ll ans=0ll;
  for(ll d:ret){
    vector<ll>B(N);
    vector<ll>mae(N+1);
    vector<ll>usi(N+1);
    mae[N]=0ll;usi[N]=0ll;
    rep(i,N){B[i]=A[i]%d;mae[i]=0ll;usi[i]=0ll;}
    sort(B.begin(),B.end());
    mae[0]=0ll;
    usi[N]=0ll;
    rep(i,N){mae[i+1]=mae[i]+B[i];}
    rep(i,N){usi[N-1-i]=usi[N-i]+(d-B[N-1-i]);}
    int flag=-1;
    rep(i,N+1){
      if(mae[i]==usi[i]&&mae[i]<=K){flag=1;}
    }
    if(flag==1){ans=max(ans,d);}
  }
  cout<<ans;
}
