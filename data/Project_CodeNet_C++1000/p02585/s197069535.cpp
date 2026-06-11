#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;


int main(){
  int n; ll K; cin >> n >> K; ll p[n]; ll c[n];
  rep(i, n){
    cin >> p[i]; p[i]--;
  }
  rep(i, n) cin >> c[i];
  ll tmp[n];
  rep(i, n) tmp[i] = -longinf;
  rep(i, n){
    ll syuki = 0; int now = i; int cnt = 0; 
    while(now!=i || cnt==0){
      syuki+=c[p[now]]; now = p[now]; cnt++;
    }
    if(syuki<=0 || K<cnt){
      ll po = 0; now = i;
      rep(j, min(K, (ll)cnt)){
        po+=c[p[now]]; now = p[now]; tmp[i] = max(tmp[i], po); 
      }
    }
    else{
      ll begin = K-cnt; ll po = syuki*((K-cnt)/cnt); int kazu = cnt + K%cnt; now = i;
      rep(j, kazu){
        po+=c[p[now]]; now = p[now]; tmp[i] = max(tmp[i], po);
      }
    }
  }
  ll ans = -longinf;
  rep(i, n){
    ans = max(ans, tmp[i]);
  }
  cout << ans << endl;
}
      