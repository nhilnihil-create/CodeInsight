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
  int X, Y, A, B, C;
  cin>>X>>Y>>A>>B>>C;
  ll tmp;
  pqueue<pair<ll, int> > que;
  for(int i=0;i<A;++i) {
    cin>>tmp;
    que.push(mp(tmp, 0));
  }
  for(int i=0;i<B;++i) {
    cin>>tmp;
    que.push(mp(tmp, 1));
  }
  for(int i=0;i<C;++i) {
    cin>>tmp;
    que.push(mp(tmp, 2));
  }
  int anum=0, bnum=0;
  ll ans = 0;
  pair<ll, int> state;
  for(int i=0;i<X+Y;++i) {
    state = que.top();que.pop();
    if(state.se==0) {
      if(anum==X) {
        i--;
        continue;
      }
      ans += state.fi;
      anum++;
    }
    if(state.se==1) {
      if(bnum==Y) {
        i--;
        continue;
      }
      ans += state.fi;
      bnum++;
    }
    if(state.se==2) {
      ans += state.fi;
    }
  }
  cout<<ans<<endl;
}

