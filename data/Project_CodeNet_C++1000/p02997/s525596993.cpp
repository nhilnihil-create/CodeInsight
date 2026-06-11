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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, K;
  cin>>N>>K;
  if(K>(N-1)*(N-2)/2) {
    cout<<-1<<endl;
    return 0;
  }
  vector<pair<int, int> > edge;
  for(int i=1;i<N;++i) edge.push_back(mp(0, i));
  int num = (N-1)*(N-2)/2;
  for(int i=1;i<N;++i) {
    for(int j=i+1;j<N;++j) {
      if(num==K) break;
      edge.push_back(mp(i, j));
      num--;
    }
  }
  cout<<edge.size()<<endl;
  for(int i=0;i<edge.size();++i) {
    cout<<edge[i].fi+1<<" "<<edge[i].se+1<<endl;
  }
}

