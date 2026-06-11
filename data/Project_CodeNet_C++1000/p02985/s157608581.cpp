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
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,K;
  cin>>N>>K;
  VI A(N-1),B(N-1);
  rep(i,N-1) cin>>A[i]>>B[i];
  VI C(N);
  ll ans=1;
  ll mod=1e9+7;
  VVI X(N,VI(0));
  rep(i,N-1){
    X[A[i]-1].pb(B[i]-1);
    X[B[i]-1].pb(A[i]-1);
  }
  C[0]=1;
  ans*=K;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int tmp=Q.front();
    Q.pop();
    ll Y=K-1;
    if(tmp==0) Y++;
    rep(i,X[tmp].size()){
      if(C[X[tmp][i]]==0){
        Y--;
        C[X[tmp][i]]=1;
        ans=ans*Y%mod;
        Q.push(X[tmp][i]);
      }
    }
  }
  cout<<ans<<endl;
}
