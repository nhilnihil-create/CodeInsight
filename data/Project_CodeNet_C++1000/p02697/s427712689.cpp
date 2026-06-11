#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)
#define MOD 1000000007

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

int main(){
  ll N, M;
  cin >> N >> M;

  rep(m, M){
    if(m % 2 == 0) printf("%lld %lld\n", 1+m/2, N-m/2);
    else printf("%lld %lld\n", (N+1)/2-1-m/2, (N+1)/2+1+m/2);
  }

  return 0;
}

