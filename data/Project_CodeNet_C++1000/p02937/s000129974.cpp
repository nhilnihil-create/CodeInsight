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
  string S, T;
  cin>>S>>T;
  map<char, vector<ll> > amap;
  for(int i=0;i<S.size();++i){
    amap[S[i]].push_back(i);
  }
  ll ans = 0;
  ll index = 0;
  int tmp;
  bool can = true;
  for(int i=0;i<T.size();++i){
    tmp = lower_bound(amap[T[i]].begin(), amap[T[i]].end(), index) - amap[T[i]].begin();
    if(amap[T[i]].size()==0){
      can = false;
      break;
    }
    else if(amap[T[i]].size()<=tmp){
      i--;
      ans += S.size()-index;
      index = 0;
      continue;
    }
    ans += amap[T[i]][tmp] - index + 1;
    index = amap[T[i]][tmp]+1;
  }
  if(can) cout<<ans<<endl;
  else cout<<-1<<endl;
}

