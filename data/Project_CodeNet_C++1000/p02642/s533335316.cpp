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
  vector<int> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  int ans[A[A.size()-1]+1];
  for(int i=0;i<=A[A.size()-1];++i) ans[i] = 0;
  map<int, int> amap;
  for(int i=0;i<N;++i) {
    if(ans[A[i]]>0) continue;
    amap[A[i]]++;
    for(int j=2;A[i]*j<=A[A.size()-1];++j) {
      ans[A[i]*j]++;
    }
  }
  int ans1 = 0;
  for(int i=0;i<=A[A.size()-1];++i) {
    if(amap[i]==1 && ans[i]==0) ans1++;
  }
  cout<<ans1<<endl;
}

