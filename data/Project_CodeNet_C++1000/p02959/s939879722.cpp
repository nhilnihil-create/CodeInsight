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
  ll A[N+1], B[N];
  for(int i=0;i<=N;++i) cin>>A[i];
  for(int i=0;i<N;++i) cin>>B[i];
  ll ans = 0;
  for(int i=0;i<N;++i) {
    if(A[i]>B[i]) {
      ans += B[i];
      A[i] -= B[i];
    }
    else {
      ans += A[i];
      B[i] -= A[i];
      A[i] = 0;
      if(A[i+1]>B[i]) {
        ans += B[i];
        A[i+1] -= B[i];
      }
      else {
        ans += A[i+1];
        B[i] -= A[i+1];
        A[i+1] = 0;
      }
    }
  }
  cout<<ans<<endl;
}

