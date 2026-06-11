#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using ll = long long;
using namespace std;
void dfs(vvi &root, vi &ans, int pos, vi &check){
  check[pos] = 1;
  for(int x : root[pos]){
    if(!check[x]){
      ans[x] += ans[pos];
      dfs(root, ans, x, check);
    }
  }
}
int main(){
  int n,q;
  cin >> n >> q;
  vvi root(n);
  vi ans(n);
  rep(i, n - 1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  rep(i, q){
    ll p,x;
    cin >> p >> x;
    ans[p - 1] += x;
  }
  vi check(n, 0);
  dfs(root, ans, 0, check);
  rep(i, n - 1) cout << ans[i] << " ";
  cout << ans[n - 1] << endl;
}