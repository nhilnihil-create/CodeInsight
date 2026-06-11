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
  ll N;
  cin>>N;
  VL U(N-1),V(N-1);
  rep(i,N-1) cin>>U[i]>>V[i];
  ll ans=0;
  rep(i,N) ans+=(i+1)*(N-i);
  rep(i,N-1){
    if(U[i]>V[i]) swap(U[i],V[i]);
    ans-=U[i]*(N+1-V[i]);
  }
  cout<<ans<<endl;
}
