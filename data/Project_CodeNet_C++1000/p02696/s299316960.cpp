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
  ll A;
  double B, N;
  cin >> A >> B >> N;

  double x = N < B ? N : B-1;
  ll ans = (ll)(A * x / B) - A * (ll)(x / B);
  cout << ans << endl;
  return 0; 
}

