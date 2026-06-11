#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,S;
  cin>>N>>S;
  VL A(N);
  rep(i,N) cin>>A[i];
  VVL X(N+1,VL(S+1,0));
  X[0][0]=1;
  ll mod=998244353;
  rep(i,N) rep(j,S+1){
    if(X[i][j]){
      X[i+1][j]=(X[i+1][j]+2*X[i][j]%mod)%mod;
      if(j+A[i]<=S) X[i+1][j+A[i]]=(X[i+1][j+A[i]]+X[i][j])%mod;
    }
  }
  cout<<X[N][S]<<endl;
}