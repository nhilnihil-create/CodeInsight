#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

int main(){
  ll N; cin >> N;
  ll d = 1;
  while(N > d) d <<= 1;
  if(N == d){
    puts("No");
  }
  else{
    puts("Yes");
    if(N < d-1) d >>= 1;
    // cout << d << endl;
    repi(i, 1, d-1){
      printf("%lld %lld\n", i, i+1);
      printf("%lld %lld\n", N+i, N+i+1);
    }
    printf("%lld %lld\n", d-1, N+1);
    if(N % 2){
      repi(i, d, N+1){
        if(i % 2) continue;
        printf("%lld %lld\n", i, i+1);
        printf("%lld %lld\n", N+i, N+i+1);
        printf("%d %lld\n", 1, i);
        printf("%d %lld\n", 1, N+i+1);
      }
    }
    else{
      repi(i, d, N-2){
        if(i % 2) continue;
        printf("%lld %lld\n", i, i+1);
        printf("%lld %lld\n", N+i, N+i+1);
        printf("%d %lld\n", 1, i);
        printf("%d %lld\n", 1, N+i+1);
      }
      printf("%lld %lld\n", N-2, N);
      printf("%lld %lld\n", 2*N-2, 2*N);
      printf("%lld %lld\n", N-2, (N-2)^N);
      printf("%lld %lld\n", 2*N, (N-2)^N);
      printf("%lld %lld\n", N-1, N-2);
      printf("%lld %lld\n", 2*N-1, ((N-2)^N)+1);
    }
  }
  return 0;
}
