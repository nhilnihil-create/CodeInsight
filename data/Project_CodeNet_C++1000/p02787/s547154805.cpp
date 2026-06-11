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

int DP[1005][10005];

int main() {
  int H, N;
  cin>>H>>N;
  int A[N], B[N];
  for(int i=0;i<N;++i) cin>>A[i]>>B[i];
  for(int j=1;j<=H;++j) {
    if(j%A[0]==0) DP[0][j] = (j/A[0])*B[0];
    else DP[0][j] = (j/A[0]+1)*B[0];
  }
  for(int i=1;i<N;++i) {
    for(int j=1;j<=H;++j) {
      if(j<=A[i]) DP[i][j] = min(DP[i-1][j], B[i]);
      else DP[i][j] = min(DP[i-1][j], min(DP[i][j-A[i]]+B[i], DP[i-1][j-A[i]]+B[i]));
    }
  }
  cout<<DP[N-1][H]<<endl;
}

