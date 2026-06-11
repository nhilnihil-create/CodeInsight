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
  queue<int> que[N];
  int tmp;
  for(int i=0;i<N;++i) {
    for(int j=0;j<N-1;++j) {
      cin>>tmp;
      tmp--;
      que[i].push(tmp);
    }
  }
  int match[N];
  for(int i=0;i<N;++i) match[i] = -1;
  int ans = 0;
  bool can;
  bool owari;
  while(true) {
    owari = true;
    for(int i=0;i<N;++i) {
      if(match[i]>-1) continue;
      if(!que[i].empty()) {
        owari = false;
        match[i] = que[i].front();que[i].pop();
      }
    }
    if(owari) break;
    ans++;
    can = false;;
    for(int i=0;i<N;++i) {
      if(match[i]==-1) continue;
      if(i==match[match[i]]) {
        can = true;
        match[match[i]] = -1;
        match[i] = -1;
      }
    }
    if(!can) break;
  }
  if(can) cout<<ans<<endl;
  else cout<<-1<<endl;
}

