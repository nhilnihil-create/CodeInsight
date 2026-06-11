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
  int N, M;
  cin>>N>>M;
  ll H[N];
  for(int i=0;i<N;++i) cin>>H[i];
  vector<vector<int> > edge(N);
  int A, B;
  for(int i=0;i<M;++i) {
    cin>>A>>B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  bool can;
  int ans = 0;
  for(int i=0;i<N;++i) {
    can = true;
    for(int j=0;j<edge[i].size();++j) {
      if(H[i]<=H[edge[i][j]]) can = false;
    }
    if(can) ans++;
  }
  cout<<ans<<endl;
}

