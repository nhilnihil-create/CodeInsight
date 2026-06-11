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
  vector<int> A;
  int amap[1000005];
  int bmap[1000005];
  for(int i=0;i<1000005;++i) {
    amap[i] = 0;
    bmap[i] = 0;
  }
  int tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    if(amap[tmp]==0) A.push_back(tmp);
    amap[tmp]++;
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for(int i=0;i<A.size();++i) {
    if(amap[A[i]]==1 && bmap[A[i]]==0) {
      ans++;
      for(int j=1;A[i]*j<=1000000;++j) bmap[A[i]*j]++;
    }
    else if(bmap[A[i]]>0) continue;
    else {
      for(int j=1;A[i]*j<=1000000;++j) bmap[A[i]*j]++;
    }
  }
  cout<<ans<<endl;
}

