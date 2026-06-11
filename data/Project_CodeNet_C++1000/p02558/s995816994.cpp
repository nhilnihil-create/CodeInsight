#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

using Pair = pair<int, int>;
using lint = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)

// const int mod = 1e9 + 7;
// const int mod = 998244353;

template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main(){
  int n,q;
  cin>>n>>q;
  dsu d(n);
  rep(i,q){
    int t,u,v;
    cin>>t>>u>>v;
    if(t==0)d.merge(u,v);
    else cout<<(int)d.same(u,v)<<endl;
  }
}
