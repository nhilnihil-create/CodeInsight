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
#include <cassert>
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
  ll N,D;
  cin>>N>>D;
  VL X(N),Y(N);
  rep(i,N) cin>>X[i]>>Y[i];
  int ans=0;
  rep(i,N){
    if(X[i]*X[i]+Y[i]*Y[i]<=D*D) ans++;
  }
  cout<<ans<<endl;
}
