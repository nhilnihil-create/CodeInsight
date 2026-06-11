#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define REP(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL
const ll MOD=1000000007;

int main(){
  ll n; cin>>n;
  ll ans = LLINF;
  for (ll i=1; i*i<=n; i++){
    if (n%i==0){
      ll a = i;
      ll b = n/i;
      ans = min(a+b, ans);
    }
  }
  cout << ans - 2 << endl;
}