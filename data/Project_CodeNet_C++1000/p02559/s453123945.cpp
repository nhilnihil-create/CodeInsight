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

#include <atcoder/convolution>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>
#include <atcoder/lazysegtree>
#include <atcoder/math>
#include <atcoder/maxflow>
#include <atcoder/mincostflow>
#include <atcoder/modint>
#include <atcoder/scc>
#include <atcoder/segtree>
#include <atcoder/string>
#include <atcoder/twosat>
using namespace atcoder;

int main(){
  int N,Q;
  cin>>N>>Q;
  VL A(N);
  rep(i,N) cin>>A[i];
  VL B(Q),C(Q),D(Q);
  rep(i,Q) cin>>B[i]>>C[i]>>D[i];
  fenwick_tree<ll> fw(N);
  rep(i,N) fw.add(i,A[i]);
  rep(i,Q){
    if(!B[i]) fw.add(C[i],D[i]);
    else cout<<fw.sum(C[i],D[i])<<endl;
  }
}

