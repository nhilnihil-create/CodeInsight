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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> pl,mi;
  rep(i,n){
    cin >> a[i];
    if(a[i]>=0){
      pl.emplace_back(a[i]);
    } else {
      mi.emplace_back(a[i]);
    }
  }
  sort(pl.rbegin(),pl.rend());
  sort(mi.begin(),mi.end());
  if(mi.empty()){
    mi.emplace_back(pl.back());
    pl.pop_back();
  }
  if(pl.empty()){
    pl.emplace_back(mi.back());
    mi.pop_back();
  }

  vector<pair<ll,ll>> act;
  ll ans = mi[0];
  int plsz = pl.size();
  rep(i,plsz-1){
    act.emplace_back(ans,pl[i]);
    ans -= pl[i];
  }
  act.emplace_back(pl[plsz-1],ans);
  ans = pl[plsz-1]-ans;

  int misz = mi.size();
  REP(i,1,misz){
    act.emplace_back(ans,mi[i]);
    ans -= mi[i];
  }

  cout << ans << endl;
  for(auto it:act){
    cout << it.F << " " << it.S << endl;
  }
  return 0;
}