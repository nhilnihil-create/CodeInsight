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
  int N, K;
  cin>>N>>K;
  int ans[N+1];
  for(int i=0;i<=N;++i) ans[i] = 0;
  for(int i=0;i<N;++i) {
    cin>>ans[i];
  }
  int next[N+1];
  bool fin;
  for(int i=0;i<K;++i) {
    for(int j=0;j<=N;++j) next[j] = 0;
    for(int j=0;j<N;++j) {
      next[max(0, j-ans[j])]++;
      next[min(N, j+ans[j]+1)]--;
    }
    for(int j=1;j<=N;++j) next[j] += next[j-1];
    for(int j=0;j<=N;++j) ans[j] = next[j];
    fin = true;
    for(int j=0;j<N;++j) {
      if(ans[j]<N) fin = false;
    }
    if(fin) break;
  }
  for(int i=0;i<N;++i) cout<<ans[i]<<" ";
  cout<<endl;
}

