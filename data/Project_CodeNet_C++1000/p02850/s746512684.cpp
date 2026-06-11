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
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pii> place(n - 1);
  vvi root(n);
  rep(i, n - 1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
    place[i] = make_pair(a, b);
  }
  int k = 0;
  rep(i, n) k = max(k, int(root[i].size()));
  queue<int> que;
  map<pii, int> ans;
  vi checked(n);
  checked[0] = 1;
  que.push(0);
  while(!que.empty()){
    int pos = que.front();
    que.pop();
    for(int x : root[pos]){
      if(!checked[x]){
        checked[x] = checked[pos] % k + 1;
        checked[pos] = checked[x];
        ans[make_pair(min(pos, x), max(pos, x))] = checked[x];
        que.push(x);
      }
    }
  }
  cout << k << endl;
  rep(i, n - 1) cout << ans[place[i]] << endl;
}