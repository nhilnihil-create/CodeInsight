#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  ll X, L;
  vector<pair<ll, ll> > robot(N);
  for(int i=0;i<N;++i) {
    cin>>X>>L;
    robot[i] = mp(X+L, X-L);
  }
  sort(robot.begin(), robot.end());
  int ans = 1;
  int haji = robot[0].fi;
  for(int i=1;i<N;++i) {
    if(robot[i].se<haji) continue;
    haji = robot[i].fi;
    ans++;
  }
  cout<<ans<<endl;
}

