#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

int main(){
  ll N; cin >> N;
  vector<ll> a(N);
  ll len = 0;
  rep(i,N){
     cin >> a.at(i);
     len += a.at(i);
  }

  ll ans = INFL,sum=0;
  rep(i,N){
    sum+=a.at(i);
    ans = min(ans,abs(len-2*sum));
  }

  cout << ans << endl;

}
