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
  ll N;
  cin>>N;
  VL P(N);
  rep(i,N) cin>>P[i];
  ll ans=0;
  multiset<ll> X;
  X.insert(-1);
  X.insert(-1);
  X.insert(N);
  X.insert(N);
  VL Q(N);
  rep(i,N) Q[P[i]-1]=i;
  reverse(all(Q));
  rep(i,N){
    auto itr=X.lb(Q[i]);
    ll B,C,D,E;
    D=*itr;
    itr++;
    E=*itr;
    itr--;
    itr--;
    C=*itr;
    itr--;
    B=*itr;
    ans+=((E-D)*(Q[i]-C)+(C-B)*(D-Q[i]))*(N-i);
    X.insert(Q[i]);
  }
  cout<<ans<<endl;
}