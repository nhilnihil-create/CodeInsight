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

ll bit[500005];

void add(int i, ll x) {
  while(i<500005) {
    bit[i] += x;
    i += i&-i;
  }
}

ll get(int i) {
  ll ans = 0;
  while(i>0) {
    ans += bit[i];
    i -= i&-i;
  }
  return ans;
}

int main() {
  int N, Q;
  cin>>N>>Q;
  ll tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    add(i+1, tmp);
  }
  int t, x1, x2;
  vector<ll> ans;
  for(int i=0;i<Q;++i) {
    cin>>t>>x1>>x2;
    if(t==0) {
      add(x1+1, x2);
    }
    else {
      ans.push_back(get(x2)-get(x1));
    }
  }
  for(int i=0;i<ans.size();++i) cout<<ans[i]<<endl;
}

