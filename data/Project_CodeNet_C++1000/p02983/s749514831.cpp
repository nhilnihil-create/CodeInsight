#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll L, R;
  cin>>L>>R;
  if(R-L>=2019) cout<<0<<endl;
  else {
    ll ans = big;
    for(ll i=L;i<=R;++i) {
      for(ll j=i+1;j<=R;++j) {
        ans = min(ans, i*j%2019);
      }
    }
    cout<<ans<<endl;
  }
}

