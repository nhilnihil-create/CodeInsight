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
  int N;
  cin>>N;
  vector<int> L(N);
  for(int i=0;i<N;++i) cin>>L[i];
  sort(L.begin(), L.end());
  int index;
  int ans = 0;
  for(int i=0;i<N;++i) {
    for(int j=i+1;j<N;++j) {
      index = lower_bound(L.begin(), L.end(), L[i]+L[j])-L.begin()-1;
      ans += index-j;
    }
  }
  cout<<ans<<endl;
}

