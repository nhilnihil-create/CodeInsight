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
  vector<int> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  int minnum = A[0];
  int maxnum = A[N-1];
  pair<int, int> ans[N-1];
  for(int i=1;i<N-1;++i) {
    if(A[i]>=0) {
      ans[i-1] = mp(minnum, A[i]);
      minnum -= A[i];
    }
    else {
      ans[i-1] = mp(maxnum, A[i]);
      maxnum -= A[i];
    }
  }
  cout<<maxnum-minnum<<endl;
  for(int i=0;i<N-2;++i) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
  cout<<maxnum<<" "<<minnum<<endl;
}

