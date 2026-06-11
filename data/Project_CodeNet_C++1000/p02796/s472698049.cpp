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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<pair<ll, ll> > arr(N);
  ll X, L;
  for(int i=0;i<N;++i) {
    cin>>X>>L;
    arr[i] = mp(X+L, X);
  }
  sort(arr.begin(), arr.end());
  ll tmp = arr[0].fi;
  int ans = 1;
  for(int i=1;i<N;++i) {
    X = arr[i].se;
    L = arr[i].fi-X;
    if(X-L<tmp) continue;
    ans++;
    tmp = X+L;
  }
  cout<<ans<<endl;
}

